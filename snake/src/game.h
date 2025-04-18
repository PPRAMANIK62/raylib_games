#ifndef GAME_H
#define GAME_H

#include "snake.h"
#include "food.h"
#include<fstream>

class Game {
  public:
    Snake snake = Snake();
    Food food = Food(snake.body);
    bool running = true;
    int score = 0;
    Sound eat_sound;
    Sound wall_sound;

    Game();
    ~Game();

    void Draw();
    void Update();
    void CheckCollisionWithFood();
    void CheckCollisionWithEdges();
    void CheckCollisionWithTail();
    void GameOver();
};

extern double last_update_time;
extern double update_interval;
extern const double speed_increment;
extern const double min_interval;

extern bool EventTriggered(double interval);
extern int LoadHighScore();
extern void SaveHighScore(int score);

#endif
