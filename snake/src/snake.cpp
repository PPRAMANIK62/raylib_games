#include "snake.h"

const int cell_size = 30;
const int cell_count = 25;
const int offset = 75;

const Color green = {173, 204, 96, 255};
const Color dark_green = {43, 51, 24, 255};

void Snake::Draw() {
  for (unsigned int i = 0; i < body.size(); i++) {
    float x = body[i].x;
    float y = body[i].y;

    Rectangle segment = Rectangle{
      offset + x * cell_size,
      offset + y * cell_size,
      (float)cell_size,
      (float)cell_size
    };

    DrawRectangleRounded(segment, 0.5, 6, dark_green);
  }
}

void Snake::Update() {
  Vector2 new_position = {
    body[0].x + direction.x,
    body[0].y + direction.y
  };
  body.push_front(new_position);

  if (add_segment) {
    add_segment = false;
  } else {
    body.pop_back();
  }
}

void Snake::Reset() {
  body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
  direction = {1, 0};
}
