#include<raylib.h>
#include "ball.h"

int main() {
  constexpr int screenWidth = 1600;
  constexpr int screenHeight = 1000;

  Ball ball;

  InitWindow(screenWidth, screenHeight, "Raylib Starter");
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    ball.Update();

    BeginDrawing();
    ClearBackground(DARKBLUE);
    ball.Draw();
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
