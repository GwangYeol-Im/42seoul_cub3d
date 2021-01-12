const TILE_SIZE = 32;
const MAP_NUM_ROWS = 11;
const MAP_NUM_COLS = 15;

const WINDOW_WIDTH = MAP_NUM_COLS * TILE_SIZE;
const WINDOW_HEIGHT = MAP_NUM_ROWS * TILE_SIZE;

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
  render() {
    for (let i = 0; i < MAP_NUM_ROWS; i++) {
      for (let j = 0; j < MAP_NUM_COLS; j++) {
        const tileX = j * TILE_SIZE;
        const tileY = i * TILE_SIZE;
        const tileColor = this.grid[i][j] === 1 ? '#222' : '#fff';
        stroke('#222'); // 테두리 설정
        fill(tileColor); // 배경색
        rect(tileX, tileY, TILE_SIZE, TILE_SIZE); // 도형
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
    this.x += Math.cos(this.rotationAngle) * moveStep;
    this.y += Math.sin(this.rotationAngle) * moveStep;
  }

  render() {
    noStroke();
    fill('red');
    circle(this.x, this.y, this.radius);
    stroke('red');
    line(
      //플레이어가 보는 방향 (x, y축에서 라디안? 을 적용)
      this.x,
      this.y,
      this.x + Math.cos(this.rotationAngle) * 20,
      this.y + Math.sin(this.rotationAngle) * 20
    );
  }
}

const grid = new Map();
const player = new Player();

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

function setup() {
  //페이지가 실행될 때 한번만 실행
  createCanvas(WINDOW_WIDTH, WINDOW_HEIGHT);
}

function update() {
  // 다음 프레임으로 넘어가기 전에 update 해야하는 부분
  player.update();
}

function draw() {
  //페이지 실행 후 매 프레임마다 실행
  update();

  grid.render();
  player.render();
}
