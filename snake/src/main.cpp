#include<raylib.h>
#include "game.h"

int main() {
  static bool allow_move = false;

  const int screenWidth = 2 * offset + cell_size * cell_count;
  const int screenHeight = screenWidth;

  InitWindow(screenWidth, screenHeight, "Retro Snake");
  SetTargetFPS(60);

  Game game = Game();

  while (!WindowShouldClose()) {
    BeginDrawing();

    if (EventTriggered(update_interval)) {
      allow_move = true;

      // save score before update
      int prev_score = game.score;

      game.Update();

      // if food was eaten increase speed
      if (game.score > prev_score && update_interval > min_interval) {
        update_interval -= speed_increment;
      }
    }

    // Game start
    if (EventTriggered(update_interval)) {
      allow_move = true;
      game.Update();
    }

    // Snake controls
    if (
      IsKeyPressed(KEY_UP) &&
      game.snake.direction.y != 1 &&
      allow_move
    ) {
      game.snake.direction = {0, -1};
      game.running = true;
      allow_move = false;
    }

    if (
      IsKeyPressed(KEY_DOWN) &&
      game.snake.direction.y != -1 &&
      allow_move
    ) {
      game.snake.direction = {0, 1};
      game.running = true;
      allow_move = false;
    }

    if (
      IsKeyPressed(KEY_LEFT) &&
      game.snake.direction.x != 1 &&
      allow_move
    ) {
      game.snake.direction = {-1, 0};
      game.running = true;
      allow_move = false;
    }

    if (
      IsKeyPressed(KEY_RIGHT) &&
      game.snake.direction.x != -1 &&
      allow_move
    ) {
      game.snake.direction = {1, 0};
      game.running = true;
      allow_move = false;
    }

    // Drawing
    ClearBackground(green);
    DrawRectangleLinesEx(
      Rectangle{
        (float)offset - 5,
        (float)offset - 5,
        (float)cell_size * cell_count + 10,
        (float)cell_size * cell_count + 10,
      },
      5,
      dark_green
    );
    DrawText(
      "Retro Snake",
      offset - 5,
      offset + cell_size * cell_count + 10,
      40,
      dark_green
    );
    DrawText(
      TextFormat("%i", game.score),
      offset + cell_size * cell_count - 15,
      offset + cell_size * cell_count + 10,
      40,
      dark_green
    );
    game.Draw();

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
