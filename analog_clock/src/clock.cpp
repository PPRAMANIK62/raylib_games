#include "clock.h"

Color dark_grey = {45, 45, 45, 255};
Color light_grey = {229, 229, 229, 255};

void Clock::Draw() const {
  DrawFace();
  DrawHourMarks();
  DrawMinuteHand(minute);
  DrawHourHand(hour, minute);
  DrawSecondHand(second);
  DrawCircleV(position, 15, dark_grey);
}

void Clock::Update() {
  std::time_t t = std::time(0);
  std::tm* now = std::localtime(&t);

  hour = now->tm_hour % 12;
  minute = now->tm_min;
  second = now->tm_sec;
}

void Clock::DrawFace() const {
  DrawCircleV(position, size, dark_grey);
  DrawCircleV(position, size - 30, light_grey);
  DrawCircleV(position, size - 40, RAYWHITE);
}

void Clock::DrawHourMarks() const {
  float rect_width = 10;
  float rect_height = size;

  Rectangle rect = {position.x, position.y, rect_width, rect_height};

  for (int i = 0; i < 12; i++) {
    DrawRectanglePro(rect, {rect_width / 2, rect_height}, i * 30, dark_grey);
  }
  DrawCircleV(position, size - 50, RAYWHITE);
}

void Clock::DrawHand(
  float hand_width,
  float hand_length,
  int angle,
  Color color,
  int offset
) const {
  Rectangle hand_rect = Rectangle{position.x, position.y, hand_width, hand_length};
  DrawRectanglePro(hand_rect, {hand_width / 2, hand_length - offset}, angle, color);
}

void Clock::DrawHourHand(int hour, int minute) const {
  float hand_width = 15;
  float hand_length = size * 0.6;
  int angle = 30 * (hour + (minute / 60.0));

  DrawHand(hand_width, hand_length, angle, dark_grey, 0);
}

void Clock::DrawMinuteHand(int minute) const {
  float hand_width = 10;
  float hand_length = size * 0.7;
  int angle = minute * 6;

  DrawHand(hand_width, hand_length, angle, dark_grey, 0);
}

void Clock::DrawSecondHand(int second) const {
  float hand_width = 5;
  float handl_length = size * 1.05;
  int angle = second * 6;

  DrawHand(hand_width, handl_length, angle, RED, 55);
}
