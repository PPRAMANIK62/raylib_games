#include "game.h"
#include<raymath.h>
#include<deque>

double last_update_time = 0;

bool EventTriggered(double interval) {
  double current_time = GetTime();
  if (current_time - last_update_time >= interval) {
    last_update_time = current_time;
    return true;
  }
  return false;
}

Game::Game() {
  // TODO: Init audio device
}

Game::~Game() {
  // TODO: Close audio device
}

void Game::Draw() {
  food.Draw();
  snake.Draw();
}

void Game::Update() {
  if (running) {
    snake.Update();
    CheckCollisionWithFood();
    CheckCollisionWithEdges();
    CheckCollisionWithTail();
  }
}

void Game::CheckCollisionWithFood() {
  if (Vector2Equals(snake.body[0], food.position)) {
    food.position = food.GenerateRandomPosition(snake.body);
    snake.add_segment = true;
    score++;
    // TODO: Play sound
  }
}

void Game::CheckCollisionWithEdges() {
  if (
    snake.body[0].x == cell_count ||
    snake.body[0].x == -1 ||
    snake.body[0].y == cell_count ||
    snake.body[0].y == -1
  ) {
    GameOver();
  }
}

void Game::GameOver() {
  snake.Reset();
  food.position = food.GenerateRandomPosition(snake.body);
  running = false;
  score = 0;
  // TODO: Play sound
}

void Game::CheckCollisionWithTail() {
  std::deque<Vector2> headless_body = snake.body;
  headless_body.pop_front();

  if (ElementInDeque(snake.body[0], headless_body)) {
    GameOver();
  }
}
