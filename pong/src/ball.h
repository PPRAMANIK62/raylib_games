#pragma once

class Ball {
  public:
    float x;
    float y;
    int speedX;
    int speedY;
    float radius;
    Ball();
    void Update();
    void Draw() const;
    void ResetBall();
};

extern int player_score;
extern int cpu_score;
