#include<raylib.h>
#include<raymath.h>
#include<deque>
#include "food.h"
#include "snake.h"

bool ElementInDeque(Vector2 element, std::deque<Vector2> deque) {
  for (unsigned int i = 0; i < deque.size(); i++) {
    if (Vector2Equals(deque[i], element)) {
      return true;
    }
  }
  return false;
}

Food::Food(std::deque<Vector2> snake_body) {
  Image image = LoadImage("graphics/food.png");
  texture = LoadTextureFromImage(image);
  UnloadImage(image);
  position = GenerateRandomPosition(snake_body);
}

Food::~Food() {
  UnloadTexture(texture);
}

void Food::Draw() {
  DrawTexture(
    texture,
    offset + position.x * cell_size,
    offset + position.y * cell_size,
    WHITE
  );
}

Vector2 Food::GenerateRandomCell() {
  float x = GetRandomValue(0, cell_count - 1);
  float y = GetRandomValue(0, cell_count - 1);
  return Vector2{x, y};
}

Vector2 Food::GenerateRandomPosition(std::deque<Vector2> snake_body) {
  Vector2 position = GenerateRandomCell();
  while (ElementInDeque(position, snake_body)) {
    position = GenerateRandomCell();
  }
  return position;
}
