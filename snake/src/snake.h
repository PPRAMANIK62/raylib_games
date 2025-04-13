#ifndef SNAKE_H
#define SNAKE_H

#include<deque>
#include<raylib.h>

class Snake {
  public:
    std::deque<Vector2> body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    Vector2 direction = {1, 0};
    bool add_segment = false;

    void Draw();
    void Update();
    void Reset();
};

// Global constants expected to be defined elsewhere
extern const int cell_size;
extern const int cell_count;
extern const int offset;
extern const Color green;
extern const Color dark_green;

#endif
