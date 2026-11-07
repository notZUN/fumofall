#ifndef ASSETS_INPUT_H
#define ASSETS_INPUT_H

#include <termios.h>

void setup_terminal();
void restore_terminal();
int get_key();

#endif
