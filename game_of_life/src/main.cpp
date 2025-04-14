#include<raylib.h>
#include "simulation.h"

int main() {
  const int screenWidth = 750;
  const int screenHeight = 750;
  const int cell_size = 25;
  int FPS = 12;

  Color grey = {29, 29, 29, 255};

  InitWindow(screenWidth, screenHeight, "Game of Life");
  SetTargetFPS(FPS);

  Simulation simulation{screenWidth, screenHeight, cell_size};

  while (!WindowShouldClose()) {
    // event handling
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
      Vector2 mouse_position = GetMousePosition();
      int row = mouse_position.y / cell_size;
      int column = mouse_position.x / cell_size;
      simulation.ToggleCell(row, column);
    }
    if (IsKeyPressed(KEY_ENTER)) {
      simulation.Start();
      SetWindowTitle("Game of Life is running...");
    } else if (IsKeyPressed(KEY_SPACE)) {
      simulation.Stop();
      SetWindowTitle("Game of Life has stopped.");
    } else if (IsKeyPressed(KEY_F)) {
      FPS += 2;
      SetTargetFPS(FPS);
    } else if (IsKeyPressed(KEY_S)) {
      if (FPS > 5) {
        FPS -= 2;
        SetTargetFPS(FPS);
      }
    } else if (IsKeyPressed(KEY_R)) {
      simulation.CreateRandomState();
    } else if (IsKeyPressed(KEY_C)) {
      simulation.ClearGrid();
    }

    // state update
    simulation.Update();

    // drawing
    BeginDrawing();
    ClearBackground(grey);
    simulation.Draw();
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
