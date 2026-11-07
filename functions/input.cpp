#include "../assets/input.h"
#include <unistd.h>
#include <fcntl.h>

static struct termios old_tio, new_tio;

void setup_terminal() {
    new_tio = old_tio;

    new_tio.c_lflag &= ~(ICANON | ECHO);
    
    new_tio.c_cc[VMIN] = 0;
    new_tio.c_cc[VTIME] = 0;

    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);
}

void restore_terminal() {
    tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
}

int get_key() {
    unsigned char c;
    if (read(STDIN_FILENO, &c, 1) == 1) {
      return c;
    }
    return -1; 
}
