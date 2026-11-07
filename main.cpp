#include <string>
#include <vector>
#include "assets.h"
#include <unistd.h>
#include <iostream>

Screen screen;
bool running = 1;

int main(){
  setup_terminal();
  Color color = {255, 0, 0};
  while(running){
    screen.resize();
    for(int i = 0; i < screen.size_y; i++){
      for(int j = 0; j < screen.size_x; j++){
        screen.push(color, j, i);
      }
        if(color.R >= 2)color.R -= 2;
    }
    if(color.B != 255) color.B = 255;
    else color.B = 0;
    switch (get_key()) {
      case 'q':
        running = 0;
      break;
    }

    color.R = 255;
    screen.paint();
    usleep(16666);
  };
  std::cout << "\033[?25h";
  std::cout << "\033[0m";
  std::cout << "\033[2J\033[H";
  restore_terminal();


  return 0;
}
