#include<raylib.h>
#include "paddle.h"

Paddle::Paddle() {
  width = 25;
  height = 180;
  speed = 6;
  x = GetScreenWidth() - width - 10;
  y = GetScreenHeight() / 2 - height / 2;
}

CPUPaddle::CPUPaddle() : Paddle() {
  x = 10;  // Only override the x position for CPU paddle
}

void Paddle::LimitMovement() {
  if (y <= 0) {
    y = 0;
  }
  if (y + height >= GetScreenHeight()) {
    y = GetScreenHeight() - height;
  }
}

void Paddle::Draw() {
  DrawRectangleRounded(Rectangle{x, y, width, height}, 0.8, 0, WHITE);
}

void Paddle::Update() {
  if (IsKeyDown(KEY_UP)) {
    y -= speed;
  } else if (IsKeyDown(KEY_DOWN)) {
    y += speed;
  }
  LimitMovement();
}

void CPUPaddle::Update(int ball_y) {
  if (y + height / 2 > ball_y) {
    y -= speed;
  } else if (y + height / 2 <= ball_y) {
    y += speed;
  }
  LimitMovement();
}
