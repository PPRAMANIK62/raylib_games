#include "game.h"
#include<raymath.h>
#include<deque>

double last_update_time = 0.0f;
double update_interval = 0.2f;
const double speed_increment = 0.01f;
const double min_interval = 0.08f;

bool EventTriggered(double interval) {
  double current_time = GetTime();
  if (current_time - last_update_time >= interval) {
    last_update_time = current_time;
    return true;
  }
  return false;
}

Game::Game() {
  InitAudioDevice();
  eat_sound = LoadSound("sounds/eat.mp3");
  wall_sound = LoadSound("sounds/wall.mp3");
}

Game::~Game() {
  UnloadSound(eat_sound);
  UnloadSound(wall_sound);
  CloseAudioDevice();
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
    PlaySound(eat_sound);
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
  PlaySound(wall_sound);
}

void Game::CheckCollisionWithTail() {
  std::deque<Vector2> headless_body = snake.body;
  headless_body.pop_front();

  if (ElementInDeque(snake.body[0], headless_body)) {
    GameOver();
  }
}

int LoadHighScore() {
  std::ifstream file("highscore.txt");

  int score = 0;
  if (file.is_open()) {
    file >> score;
  }
  return score;
}

void SaveHighScore(int score) {
  std::ofstream file("highscore.txt");

  if (file.is_open()) {
    file << score;
  }
}
