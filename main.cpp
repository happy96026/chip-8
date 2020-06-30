/*
 * GLUT - The OpenGL Utility Toolkit (Graphics)
 * SDL - Simple DirectMedia Layer (Sound)
 */

#include "chip8.h"
#include "io.h"

Chip8 chip8;
IO io;

int main(int argc, char **argv) {
  io.setup_graphics();
  io.setup_input();

  chip8.init();
  chip8.load_game("pong");
  
  while (true) {
    chip8.emulate_cycle();

    if (chip8.draw_flag)
      io.draw_graphics();

    chip8.set_keys();
  }
}
