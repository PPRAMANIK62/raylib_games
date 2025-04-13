#include<raylib.h>
#include "clock.h"

int main() {
  constexpr int screenWidth = 600;
  constexpr int screenHeight = 600;

  Color light_blue = {225, 239, 240, 255};

  InitWindow(screenWidth, screenHeight, "Analog Clock");
  SetTargetFPS(15);

  Clock clock {250, {300, 300}};

  while (!WindowShouldClose()) {
    clock.Update();

    BeginDrawing();
    ClearBackground(light_blue);
    clock.Draw();
    EndDrawing();
  }

  CloseWindow();

  return 0;
}
