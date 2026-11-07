#include "../assets/screen.h"
#include <unistd.h>
#include <sys/ioctl.h>

void get_terminal_size(int &sz_x, int &sz_y){
  struct winsize ws;
  if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0 || ws.ws_row == 0) return;
  sz_x = ws.ws_col;
  sz_y = ws.ws_row;
}
