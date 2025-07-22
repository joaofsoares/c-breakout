#include <raylib.h>
#include <stdio.h>

typedef struct {
  int x;
  int y;
} Position;

typedef struct {
  Position pos;
  int width;
  int height;
  Color color;
} Bar;

typedef struct {
  Vector2 pos;
  int radius;
  Color color;
} Ball;

typedef struct {
  Position pos;
  int width;
  int height;
  Color color;
  bool is_active;
} Brick;

Vector2 ball_speed = {5.0f, 4.0f};

#define WIDTH 800
#define HEIGHT 600

#define BRICK_COUNT 40
#define BRICK_WIDTH 50
#define BRICK_HEIGHT 20

#define BRICK_POS_X 120
#define BRICK_POS_Y 40

int main(void) {

  InitWindow(WIDTH, HEIGHT, "Breakout Game");

  SetTargetFPS(60);

  Brick bricks[BRICK_COUNT] = {
      {{BRICK_POS_X, BRICK_POS_Y}, BRICK_WIDTH, BRICK_HEIGHT, RED, true},
      {{BRICK_POS_X, BRICK_POS_Y + 30},
       BRICK_WIDTH,
       BRICK_HEIGHT,
       ORANGE,
       true},
      {{BRICK_POS_X, BRICK_POS_Y + 60},
       BRICK_WIDTH,
       BRICK_HEIGHT,
       YELLOW,
       true},
      {{BRICK_POS_X, BRICK_POS_Y + 90},
       BRICK_WIDTH,
       BRICK_HEIGHT,
       LIGHTGRAY,
       true},
      {{BRICK_POS_X + 60, BRICK_POS_Y}, BRICK_WIDTH, BRICK_HEIGHT, RED, true},
      {{BRICK_POS_X + 60, BRICK_POS_Y + 30},
       BRICK_WIDTH,
       BRICK_HEIGHT,
       ORANGE,
       true},
      {{BRICK_POS_X + 60, BRICK_POS_Y + 60},
       BRICK_WIDTH,
       BRICK_HEIGHT,
       YELLOW,
       true},
      {{BRICK_POS_X + 60, BRICK_POS_Y + 90},
       BRICK_WIDTH,
       BRICK_HEIGHT,
       LIGHTGRAY,
       true},
      {{BRICK_POS_X + 120, BRICK_POS_Y}, BRICK_WIDTH, BRICK_HEIGHT, RED, true},
      {{BRICK_POS_X + 120, BRICK_POS_Y + 30},
       BRICK_WIDTH,
       BRICK_HEIGHT,
       ORANGE,
       true},
      {{BRICK_POS_X + 120, BRICK_POS_Y + 60},
       BRICK_WIDTH,
       BRICK_HEIGHT,
       YELLOW,
       true},
      {{BRICK_POS_X + 120, BRICK_POS_Y + 90},
       BRICK_WIDTH,
       BRICK_HEIGHT,
       LIGHTGRAY,
       true},
      {{BRICK_POS_X + 180, BRICK_POS_Y}, BRICK_WIDTH, BRICK_HEIGHT, RED, true},
      {{BRICK_POS_X + 180, BRICK_POS_Y + 30},
       BRICK_WIDTH,
       BRICK_HEIGHT,
       ORANGE,
       true},
      {{BRICK_POS_X + 180, BRICK_POS_Y + 60},
       BRICK_WIDTH,
       BRICK_HEIGHT,
       YELLOW,
       true},
      {{BRICK_POS_X + 180, BRICK_POS_Y + 90},
       BRICK_WIDTH,
       BRICK_HEIGHT,
       LIGHTGRAY,
       true},
      {{BRICK_POS_X + 240, BRICK_POS_Y}, BRICK_WIDTH, BRICK_HEIGHT, RED, true},
      {{BRICK_POS_X + 240, BRICK_POS_Y + 30},
       BRICK_WIDTH,
       BRICK_HEIGHT,
       ORANGE,
       true},
      {{BRICK_POS_X + 240, BRICK_POS_Y + 60},
       BRICK_WIDTH,
       BRICK_HEIGHT,
       YELLOW,
       true},
      {{BRICK_POS_X + 240, BRICK_POS_Y + 90},
       BRICK_WIDTH,
       BRICK_HEIGHT,
       LIGHTGRAY,
       true},
      {{BRICK_POS_X + 300, BRICK_POS_Y}, BRICK_WIDTH, BRICK_HEIGHT, RED, true},
      {{BRICK_POS_X + 300, BRICK_POS_Y + 30},
       BRICK_WIDTH,
       BRICK_HEIGHT,
       ORANGE,
       true},
      {{BRICK_POS_X + 300, BRICK_POS_Y + 60},
       BRICK_WIDTH,
       BRICK_HEIGHT,
       YELLOW,
       true},
      {{BRICK_POS_X + 300, BRICK_POS_Y + 90},
       BRICK_WIDTH,
       BRICK_HEIGHT,
       LIGHTGRAY,
       true},
      {{BRICK_POS_X + 360, BRICK_POS_Y}, BRICK_WIDTH, BRICK_HEIGHT, RED, true},
      {{BRICK_POS_X + 360, BRICK_POS_Y + 30},
       BRICK_WIDTH,
       BRICK_HEIGHT,
       ORANGE,
       true},
      {{BRICK_POS_X + 360, BRICK_POS_Y + 60},
       BRICK_WIDTH,
       BRICK_HEIGHT,
       YELLOW,
       true},
      {{BRICK_POS_X + 360, BRICK_POS_Y + 90},
       BRICK_WIDTH,
       BRICK_HEIGHT,
       LIGHTGRAY,
       true},
      {{BRICK_POS_X + 420, BRICK_POS_Y}, BRICK_WIDTH, BRICK_HEIGHT, RED, true},
      {{BRICK_POS_X + 420, BRICK_POS_Y + 30},
       BRICK_WIDTH,
       BRICK_HEIGHT,
       ORANGE,
       true},
      {{BRICK_POS_X + 420, BRICK_POS_Y + 60},
       BRICK_WIDTH,
       BRICK_HEIGHT,
       YELLOW,
       true},
      {{BRICK_POS_X + 420, BRICK_POS_Y + 90},
       BRICK_WIDTH,
       BRICK_HEIGHT,
       LIGHTGRAY,
       true},
      {{BRICK_POS_X + 480, BRICK_POS_Y}, BRICK_WIDTH, BRICK_HEIGHT, RED, true},
      {{BRICK_POS_X + 480, BRICK_POS_Y + 30},
       BRICK_WIDTH,
       BRICK_HEIGHT,
       ORANGE,
       true},
      {{BRICK_POS_X + 480, BRICK_POS_Y + 60},
       BRICK_WIDTH,
       BRICK_HEIGHT,
       YELLOW,
       true},
      {{BRICK_POS_X + 480, BRICK_POS_Y + 90},
       BRICK_WIDTH,
       BRICK_HEIGHT,
       LIGHTGRAY,
       true},
      {{BRICK_POS_X + 540, BRICK_POS_Y}, BRICK_WIDTH, BRICK_HEIGHT, RED, true},
      {{BRICK_POS_X + 540, BRICK_POS_Y + 30},
       BRICK_WIDTH,
       BRICK_HEIGHT,
       ORANGE,
       true},
      {{BRICK_POS_X + 540, BRICK_POS_Y + 60},
       BRICK_WIDTH,
       BRICK_HEIGHT,
       YELLOW,
       true},
      {{BRICK_POS_X + 540, BRICK_POS_Y + 90},
       BRICK_WIDTH,
       BRICK_HEIGHT,
       LIGHTGRAY,
       true}};

  Bar bar = {{WIDTH / 2 - 50, HEIGHT - 100}, 100, 20, GREEN};

  Ball ball = {{.x = ((float)WIDTH) / 2, .y = HEIGHT - 125}, 10, WHITE};

  int framesCounter = 0;

  InitWindow(WIDTH, HEIGHT, "breakout");

  SetTargetFPS(60);

  bool collision_bar = false;
  bool collision_brick = false;
  bool win = false;
  bool start_pressed = false;
  int remaining_bricks = BRICK_COUNT;

  while (!WindowShouldClose()) {

    if (IsKeyPressed(KEY_SPACE) && !start_pressed) {
      start_pressed = true;
    }

    if (IsKeyDown(KEY_RIGHT) && bar.pos.x < WIDTH - bar.width) {
      bar.pos.x += 10;
    }

    if (IsKeyDown(KEY_LEFT) && bar.pos.x > 0) {
      bar.pos.x -= 10;
    }

    for (int i = 0; i < BRICK_COUNT; i++) {
      collision_brick = CheckCollisionCircleRec(
          ball.pos, ball.radius,
          (Rectangle){bricks[i].pos.x, bricks[i].pos.y, bricks[i].width,
                      bricks[i].height});

      if (collision_brick && bricks[i].is_active) {
        bricks[i].is_active = false;
        remaining_bricks--;
        ball_speed.y *= -1.0f;
        if (ball.pos.x < bricks[i].pos.x ||
            ball.pos.x > bricks[i].pos.x + bricks[i].width) {
          ball_speed.x *= -1.0f;
        }
      }
    }

    collision_bar = CheckCollisionCircleRec(
        ball.pos, ball.radius,
        (Rectangle){bar.pos.x, bar.pos.y, bar.width, bar.height});

    if (collision_bar) {
      if (ball.pos.y + ball.radius >= bar.pos.y) {
        ball_speed.y *= -1.0f;
      }
      if (ball.pos.x < bar.pos.x || ball.pos.x > bar.pos.x + bar.width) {
        ball_speed.x *= -1.0f;
      }
    }

    if (!win && start_pressed) {
      ball.pos.x += ball_speed.x;
      ball.pos.y += ball_speed.y;

      if ((ball.pos.x >= (WIDTH - ball.radius)) ||
          (ball.pos.x <= ball.radius)) {
        ball_speed.x *= -1.0f;
      }

      if ((ball.pos.y >= (HEIGHT - ball.radius)) ||
          (ball.pos.y <= ball.radius)) {
        ball_speed.y *= -1.0f;
      }
    }

    BeginDrawing();

    ClearBackground(BLACK);

    for (int i = 0; i < BRICK_COUNT; i++) {
      if (bricks[i].is_active) {
        DrawRectangle(bricks[i].pos.x, bricks[i].pos.y, bricks[i].width,
                      bricks[i].height, bricks[i].color);
      }
    }

    DrawCircleV(ball.pos, (float)ball.radius, ball.color);
    DrawRectangle(bar.pos.x, bar.pos.y, bar.width, bar.height, bar.color);

    if (remaining_bricks == 0) {
      win = true;
      DrawText("You win!", WIDTH / 2 - MeasureText("You win!", 20) / 2,
               HEIGHT / 2 - 10, 20, GREEN);
    }

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
