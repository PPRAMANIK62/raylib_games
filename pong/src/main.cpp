#include<raylib.h>
#include "ball.h"
#include "paddle.h"

Color Green = Color{38, 185, 154, 255};
Color Dark_Green = Color{20, 160, 133, 255};
Color Light_Green = Color{129, 204, 184, 255};
Color Yellow = Color{243, 213, 91, 255};

int main() {
  constexpr int screenWidth = 1600;
  constexpr int screenHeight = 1000;

  InitWindow(screenWidth, screenHeight, "Pong Game");
  SetTargetFPS(60);

  Ball ball;
  Paddle player;
  CPUPaddle cpu;

  bool game_over = false;

  while (!WindowShouldClose()) {
    BeginDrawing();

    if (!game_over) {
      // Updating
      ball.Update();
      player.Update();
      cpu.Update(ball.y);

      // Check for collisons
      if (CheckCollisionCircleRec(
        {ball.x, ball.y},
        ball.radius,
        {player.x, player.y, player.width, player.height}
      ) || CheckCollisionCircleRec(
        {ball.x, ball.y},
        ball.radius,
        {cpu.x, cpu.y, cpu.width, cpu.height}
      )) {
        ball.speedX *= -1;
      }

      // Drawing
      ClearBackground(Dark_Green);

      // Draw field
      DrawRectangle(screenWidth / 2, 0, screenWidth / 2, screenHeight, Green);
      DrawCircle(screenWidth / 2, screenHeight / 2, 150, Light_Green);
      DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);

      // Draw objects
      ball.Draw();
      player.Draw();
      cpu.Draw();

      // Draw scores
      DrawText(TextFormat("%i", cpu_score), screenWidth / 4 - 20, 20, 80, WHITE);
      DrawText(TextFormat("%i", player_score), 3 * screenWidth / 4 - 20, 20, 80, WHITE);

      // Check win condition
      if (player_score >= 10 || cpu_score >= 10) {
        game_over = true;
      }
    } else {
      const char* winner = (player_score >= 10) ? "You Win!" : "CPU Wins!";
      DrawText(winner, screenWidth / 2 - MeasureText(winner, 80) / 2, screenHeight / 2 - 40, 80, YELLOW);
      DrawText("Press [R] to Restart", screenWidth / 2 - MeasureText("Press [R] to Restart", 40) / 2, screenHeight / 2 + 60, 40, WHITE);

      if (IsKeyPressed(KEY_R)) {
        // Reset game state
        player_score = 0;
        cpu_score = 0;
        ball.ResetBall();
        game_over = false;
      }
    }

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
