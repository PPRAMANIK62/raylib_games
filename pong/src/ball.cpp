#include<raylib.h>
#include "ball.h"
#include "paddle.h"

int player_score = 0;
int cpu_score = 0;

Ball::Ball() {
  x = GetScreenWidth() / 2;
  y = GetScreenHeight() / 2;
  speedX = 8;
  speedY = 8;
  radius = 20;
}

void Ball::Update() {
  x += speedX;
  y += speedY;

  if ((y + radius >= GetScreenHeight()) || (y - radius <= 0)) {
    speedY *= -1;
  }

  // CPU wins
  if (x + radius >= GetScreenWidth()) {
    cpu_score++;
    ResetBall();
  }
  // Player wins
  if (x - radius <= 0) {
    player_score++;
    ResetBall();
  }
}

void Ball::Draw() const {
  DrawCircle(x, y, radius, YELLOW);
}

void Ball::ResetBall() {
  x = GetScreenWidth()/2;
  y = GetScreenHeight()/2;

  int speed_choices[2] = {-1, 1};
  speedX *= speed_choices[GetRandomValue(0, 1)];
  speedY *= speed_choices[GetRandomValue(0, 1)];
}
