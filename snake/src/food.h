#ifndef FOOD_H
#define FOOD_H

#include<raylib.h>
#include<deque>

class Food {
  public:
    Vector2 position;
    Texture2D texture;

    Food(std::deque<Vector2> snake_body);
    ~Food();

    void Draw();
    Vector2 GenerateRandomCell();
    Vector2 GenerateRandomPosition(std::deque<Vector2> snake_body);
};

extern bool ElementInDeque(Vector2 element, std::deque<Vector2> deque);

#endif
