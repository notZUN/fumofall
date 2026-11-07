#include "../assets.h"
#include <unistd.h>
#include <string>
#include <sys/ioctl.h>
#include <cstdint>

const char* BLOCK = "\xE2\x96\x88";

void Color::reset(uint8_t r, uint8_t g, uint8_t b){
  R = r;
  G = g;
  B = b;
};

Screen::Screen(){
  write(STDOUT_FILENO, "\033[?25l", 6);
  resize();
};

void Screen::resize(){
  get_terminal_size(size_x, size_y);
  frame.resize(size_x * size_y);
  frame_f.reserve(size_x * size_y * 22 + 1024);
};

void Screen::clear(){
  for(auto &p: frame){
    p = transparent;
  }
  frame_f.clear();
};

void Screen::push(Color px, int x, int y){
  frame[y * size_x + x] = px;
};

void Screen::paint(){
  frame_f.clear();
  frame_f += "\033[H";
  for(int i = 0; i < size_y; i++){
    for(int j = 0; j < size_x; j++){
      frame_f += "\033[38;2;";
      frame_f += std::to_string(frame[i * size_x + j].R);
      frame_f += ';';
      frame_f += std::to_string(frame[i * size_x + j].G);
      frame_f += ';';
      frame_f += std::to_string(frame[i * size_x + j].B);
      frame_f += 'm';
      frame_f += BLOCK;
    }
    if(i != size_y - 1)screen.frame_f += "\r\n";
  } 
  write(STDOUT_FILENO, frame_f.data(), frame_f.size());
  clear();
};
