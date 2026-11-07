#ifndef ASSETS_SCREEN_H
#define ASSETS_SCREEN_H
#include <string>
#include <cstdint>
#include <vector>

class Color{
  public:
    uint8_t R;
    uint8_t G;
    uint8_t B;

    void reset(uint8_t r, uint8_t g, uint8_t b);
};

constexpr Color transparent = {3, 9, 27};

class Screen{
  public:
    int size_x;
    int size_y;
    std::vector<Color> frame;
    std::string frame_f;
  
    Screen();
    void resize();
    void clear();
    void push(Color px, int x, int y);
    void paint();
};

extern Screen screen;

#endif
