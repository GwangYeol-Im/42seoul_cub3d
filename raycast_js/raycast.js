const TILE_SIZE = 64;
const MAP_NUM_ROWS = 11;
const MAP_NUM_COLS = 15;

const WINDOW_WIDTH = MAP_NUM_COLS * TILE_SIZE;
const WINDOW_HEIGHT = MAP_NUM_ROWS * TILE_SIZE;

const FOV_ANGLE = 60 * (Math.PI / 180);

const WALL_STRIP_WIDTH = 1; //ray를 쏘았을 때 각 칼럼의 너비
const NUM_RAYS = WINDOW_WIDTH / WALL_STRIP_WIDTH;

const MINIMAP_SCALE_FACTOR = 0.2;

// 지도
class Map {
  constructor() {
    this.grid = [
      [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1],
      [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1],
      [1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1],
      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1],
      [1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1],
      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
      [1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1],
      [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1],
      [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
    ];
  }

  hasWallAt(x, y) {
    if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT) {
      return true; // 맵의 범위 안에 들어있는지 파악
    }
    // 현재 위치를 타일 사이즈로 나누어 int 형으로 치환해 인덱스 비교
    let mapGridIndexX = Math.floor(x / TILE_SIZE);
    let mapGridIndexY = Math.floor(y / TILE_SIZE);
    return this.grid[mapGridIndexY][mapGridIndexX] !== 0;
  }

  render() {
    for (let i = 0; i < MAP_NUM_ROWS; i++) {
      for (let j = 0; j < MAP_NUM_COLS; j++) {
        const tileX = j * TILE_SIZE;
        const tileY = i * TILE_SIZE;
        const tileColor = this.grid[i][j] === 1 ? '#222' : '#fff';
        stroke('#222'); // 테두리 설정
        fill(tileColor); // 배경색
        rect(
          MINIMAP_SCALE_FACTOR * tileX,
          MINIMAP_SCALE_FACTOR * tileY,
          MINIMAP_SCALE_FACTOR * TILE_SIZE,
          MINIMAP_SCALE_FACTOR * TILE_SIZE
        ); // 도형
      }
    }
  }
}

// 플레이어
class Player {
  constructor() {
    this.x = WINDOW_WIDTH / 2;
    this.y = WINDOW_HEIGHT / 2; //플레이어 위치는 정중앙
    this.radius = 3;
    this.turnDirection = 0; // 플레이어의 회전 방향
    this.walkDirection = 0; // 플레이어의 전진 방향
    this.rotationAngle = Math.PI / 2; // 회전 각도: 직각
    this.moveSpeed = 2; // 이동 속도
    this.rotationSpeed = 2 * (Math.PI / 180);
  }

  update() {
    // 플레이어의 위치와 방향 업데이트
    let moveStep = this.walkDirection * this.moveSpeed; //방향 * 속도
    // 키보드 이벤트로 회전방향이 변하니 매 프레임마다 update
    this.rotationAngle += this.turnDirection * this.rotationSpeed;
    let newPlayerX = this.x + Math.cos(this.rotationAngle) * moveStep;
    let newPlayerY = this.y + Math.sin(this.rotationAngle) * moveStep;

    if (!grid.hasWallAt(newPlayerX, newPlayerY)) {
      //벽에 부딪히는 지 검사하는 로직
      this.x = newPlayerX;
      this.y = newPlayerY;
    }
  }

  render() {
    noStroke();
    fill('blue');
    circle(
      MINIMAP_SCALE_FACTOR * this.x,
      MINIMAP_SCALE_FACTOR * this.y,
      MINIMAP_SCALE_FACTOR * this.radius
    );
    stroke('blue');
    line(
      //플레이어가 보는 방향 (x, y축에서 라디안? 을 적용)
      MINIMAP_SCALE_FACTOR * this.x,
      MINIMAP_SCALE_FACTOR * this.y,
      MINIMAP_SCALE_FACTOR * (this.x + Math.cos(this.rotationAngle) * 30),
      MINIMAP_SCALE_FACTOR * (this.y + Math.sin(this.rotationAngle) * 30)
    );
  }
}

// 레이
class Ray {
  constructor(rayAngle) {
    this.rayAngle = normalizeAngle(rayAngle);
    this.wallHitX = 0;
    this.wallHitY = 0;
    this.distance = 0; // 부딪히 벽과 플레이어 사이 거리
    this.wasHitVertical;

    this.isRayFacingDown = this.rayAngle > 0 && this.rayAngle < Math.PI;
    this.isRayFacingUp = !this.isRayFacingDown;

    this.isRayFacingRight =
      this.rayAngle < 0.5 * Math.PI || this.rayAngle > 1.5 * Math.PI;
    this.isRayFacingLeft = !this.isRayFacingRight;
  }

  cast(columnId) {
    let xintercept, yintercept;
    let xstep, ystep;
    // 수평 처리
    let foundHorzWallHit = false;
    let horzWallHitX = 0;
    let horzWallHitY = 0;

    // 수평선에서 벽과 부딪히는 y좌표 구하기
    yintercept = Math.floor(player.y / TILE_SIZE) * TILE_SIZE;
    yintercept += this.isRayFacingDown ? TILE_SIZE : 0;
    // 수평선에서 벽과 부딪히는 x좌표 구하기
    xintercept = player.x + (yintercept - player.y) / Math.tan(this.rayAngle);

    // xstep, ystep 계산
    ystep = TILE_SIZE;
    ystep *= this.isRayFacingUp ? -1 : 1;

    xstep = TILE_SIZE / Math.tan(this.rayAngle);
    xstep *= this.isRayFacingLeft && xstep > 0 ? -1 : 1;
    xstep *= this.isRayFacingRight && xstep < 0 ? -1 : 1;

    let nextHorzTouchX = xintercept;
    let nextHorzTouchY = yintercept;

    while (
      nextHorzTouchX >= 0 &&
      nextHorzTouchX <= WINDOW_WIDTH &&
      nextHorzTouchY >= 0 &&
      nextHorzTouchY <= WINDOW_HEIGHT
    ) {
      if (
        grid.hasWallAt(
          nextHorzTouchX,
          nextHorzTouchY - (this.isRayFacingUp ? 1 : 0)
        )
      ) {
        foundHorzWallHit = true;
        horzWallHitX = nextHorzTouchX;
        horzWallHitY = nextHorzTouchY;
        break;
      } else {
        nextHorzTouchX += xstep;
        nextHorzTouchY += ystep;
      }
    }
    // 수직 처리
    let foundVertWallHit = false;
    let vertWallHitX = 0;
    let vertWallHitY = 0;

    // 수직선에서 벽과 부딪히는 x좌표 구하기
    xintercept = Math.floor(player.x / TILE_SIZE) * TILE_SIZE;
    xintercept += this.isRayFacingRight ? TILE_SIZE : 0;
    // 수직선에서 벽과 부딪히는 y좌표 구하기
    yintercept = player.y + (xintercept - player.x) * Math.tan(this.rayAngle);

    // xstep, ystep 계산
    xstep = TILE_SIZE;
    xstep *= this.isRayFacingLeft ? -1 : 1;

    ystep = TILE_SIZE * Math.tan(this.rayAngle);
    ystep *= this.isRayFacingUp && ystep > 0 ? -1 : 1;
    ystep *= this.isRayFacingDown && ystep < 0 ? -1 : 1;

    let nextVertTouchX = xintercept;
    let nextVertTouchY = yintercept;

    while (
      nextVertTouchX >= 0 &&
      nextVertTouchX <= WINDOW_WIDTH &&
      nextVertTouchY >= 0 &&
      nextVertTouchY <= WINDOW_HEIGHT
    ) {
      if (
        grid.hasWallAt(
          nextVertTouchX - (this.isRayFacingLeft ? 1 : 0),
          nextVertTouchY
        )
      ) {
        foundVertWallHit = true;
        vertWallHitX = nextVertTouchX;
        vertWallHitY = nextVertTouchY;
        break;
      } else {
        nextVertTouchX += xstep;
        nextVertTouchY += ystep;
      }
    }
    // 수직, 수평까지의 거리를 계산해 더 짧은 값을 취한다.
    var horzHitDistance = foundHorzWallHit
      ? distanceBetweenPoints(player.x, player.y, horzWallHitX, horzWallHitY)
      : Number.MAX_VALUE;
    var vertHitDistance = foundVertWallHit
      ? distanceBetweenPoints(player.x, player.y, vertWallHitX, vertWallHitY)
      : Number.MAX_VALUE;

    // 수직 수평 비교해 작은 값만 저장
    this.wallHitX =
      horzHitDistance < vertHitDistance ? horzWallHitX : vertWallHitX;
    this.wallHitY =
      horzHitDistance < vertHitDistance ? horzWallHitY : vertWallHitY;
    this.distance =
      horzHitDistance < vertHitDistance ? horzHitDistance : vertHitDistance;
    this.wasHitVertical = vertHitDistance < horzHitDistance;
  }

  render() {
    stroke('rgba(255, 0, 0, 0.3)');
    line(
      MINIMAP_SCALE_FACTOR * player.x,
      MINIMAP_SCALE_FACTOR * player.y,
      MINIMAP_SCALE_FACTOR * this.wallHitX,
      MINIMAP_SCALE_FACTOR * this.wallHitY
    );
  }
}

const grid = new Map();
const player = new Player();
let rays = [];

// 각 함수들이 p5.js 내에서 이벤트 리스너의 콜백으로 등록되어 있다.
// 상수도 저장되어있는 듯
function keyPressed() {
  // 키보드 이벤트 : 눌렀을 때
  if (keyCode === UP_ARROW) {
    player.walkDirection = +1;
  } else if (keyCode === DOWN_ARROW) {
    player.walkDirection = -1;
  } else if (keyCode === RIGHT_ARROW) {
    player.turnDirection = +1;
  } else if (keyCode === LEFT_ARROW) {
    player.turnDirection = -1;
  }
}

function keyReleased() {
  // 키보드 이벤트 : 뗐을 때
  if (keyCode === UP_ARROW) {
    player.walkDirection = 0;
  } else if (keyCode === DOWN_ARROW) {
    player.walkDirection = 0;
  } else if (keyCode === RIGHT_ARROW) {
    player.turnDirection = 0;
  } else if (keyCode === LEFT_ARROW) {
    player.turnDirection = 0;
  }
}

function castAllRays() {
  let columnId = 0;
  // 플레이어 회전 각도(직각)에서 FOV / 2 (30도) 차감 -> ?
  let rayAngle = player.rotationAngle - FOV_ANGLE / 2;
  // 광선을 쏘는 모든 칼럼을 순회
  rays = []; // ray 정보를 update 할 때 계속 초기화 해야함
  for (let i = 0; i < NUM_RAYS; i++) {
    const ray = new Ray(rayAngle);
    ray.cast(columnId);
    rays.push(ray);
    rayAngle += FOV_ANGLE / NUM_RAYS;
    columnId++;
  }
}

function render3DProjectedWalls() {
  for (let i = 0; i < NUM_RAYS; i++) {
    let ray = rays[i];
    let correctWallDistance =
      ray.distance * Math.cos(ray.rayAngle - player.rotationAngle);
    // calculate the distance to the projection plane
    let distanceProjectionPlane = WINDOW_WIDTH / 2 / Math.tan(FOV_ANGLE / 2);
    // projected wall height
    let wallStripHeight =
      (TILE_SIZE / correctWallDistance) * distanceProjectionPlane;
    fill('rgba(255, 255, 255, 1.0)');
    noStroke();
    rect(
      i * WALL_STRIP_WIDTH,
      WINDOW_HEIGHT / 2 - wallStripHeight / 2,
      WALL_STRIP_WIDTH,
      wallStripHeight
    );
  }
}

function normalizeAngle(angle) {
  angle = angle % (2 * Math.PI);
  if (angle < 0) {
    angle = 2 * Math.PI + angle;
  }
  return angle;
}

function distanceBetweenPoints(x1, y1, x2, y2) {
  return Math.sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

function setup() {
  //페이지가 실행될 때 한번만 실행
  createCanvas(WINDOW_WIDTH, WINDOW_HEIGHT);
}

function update() {
  // 다음 프레임으로 넘어가기 전에 update 해야하는 부분
  player.update();
  castAllRays();
}

function draw() {
  //페이지 실행 후 매 프레임마다 실행
  clear('#212121');
  update();

  render3DProjectedWalls();

  grid.render();
  for (ray of rays) {
    ray.render();
  }
  player.render();
}
