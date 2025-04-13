#pragma once
#include<raylib.h>
#include<ctime>

class Clock {
  public:
    Clock(int size, Vector2 position): size(size), position(position), hour(0), minute(0), second(0) {};
    void Draw() const;
    void Update();

  private:
    int size;
    Vector2 position;
    int hour;
    int minute;
    int second;
    void DrawFace() const;
    void DrawHourMarks() const;
    void DrawHand(float hand_width, float hand_length, int angle, Color color, int offset) const;
    void DrawHourHand(int hour, int minute) const;
    void DrawMinuteHand(int minute) const;
    void DrawSecondHand(int second) const;
};
