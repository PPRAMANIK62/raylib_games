#pragma once

class Paddle {
  public:
    float x;
    float y;
    float height;
    float width;
    int speed;
    Paddle();
    void Draw();
    void Update();
    void LimitMovement();
};

class CPUPaddle : public Paddle {
  public:
    CPUPaddle();
    void Update(int ball_y);
};
