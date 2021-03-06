# 42seoul_cub3d

## Common Instructions

- norm 규칙에 맞게 프로젝트 작성
- 적절한 예외 처리 (seg fault, bus error etc.)
- 메모리 누수 방지
- Makefile 제출
- Makefile rule
- libft 허용 가능

## Mandatory part

- Program name: cub3d
- Turn in files: All your files
- Makefile: all, clean, fclean, re, bonus
- Arguments: a map in format \*.cub
- External functions
  - open, close, read, write, malloc, free, perror, strerror, exit
  - All functions of the math library
  - All functions of the MinilibX
- Libft authorized: Yes

- [x] miniLibX 사용하기
- [ ] 윈도우 관리 (최소화, 창 전환)
- [ ] 벽의 방향 (동, 서, 남, 북)에 따라 다른 질감의 벽을 표시하기
- [ ] 벽 대신 아이템(스프라이트) 표시
- [ ] 바닥과 천장의 색을 서로 다르게 설정
- [x] .cub 확장자를 가진 맵 파일을 첫 번쨰 인수로 받는다.
  - 지도는 4개의 문자로만 구성된다. (빈 공간: 0, 벽: 1, 아이템 2, 플레이어 출발 위치 + 바라보는 방향: N, S, E, W)
  - 지도는 벽으로 둘러쌓여 있어야 함. 그렇지 않으면 오류 반환
  - 지도 내용을 제외하고, 각 요소들은 하나 혹은 그 이상의 빈 줄로 분리될 수 있다.
  - 지도 내용은 항상 마지막에 위치, 나머지 요소들의 순서는 상관 없다.
  - 공백도 지도의 유효한 부분이며, 그 처리는 자율적으로
- [ ] 프로그램의 두 번째 인자가 "--save" 일 경우, 첫 번쨰 렌더링된 이미지를 bmp 형식으로 저장하기
- [ ] 두 번째 인자가 없을 경우, 프로그램은 다음 규칙을 준수하면서 화면 창에 영상을 표시
  - [ ] 왼쪽, 오른쪽 화살표 키는 미로에서 왼쪽과 오른쪽을 볼 수 있도록 처리
  - [ ] W, A, S, D 키는 미로를 통해 시점을 이동하도록 처리
  - [ ] ESC를 누르면 창이 닫히고 프로그램이 정상 종료되도록 처리
  - [ ] 창 상단의 빨간 십자가를 클릭하면 창이 닫히고 프로그램이 정상 종료되도록 처리
  - [ ] 지도에 표시된 화면 크기가 디스플레이 해상도보다 크면 현재 디스플레이 해상도에 따라 윈도우 크기 설정
  - [ ] miniLibX 이미지를 사용하기
