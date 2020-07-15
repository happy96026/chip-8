#pragma once

class Chip8 {
  unsigned short opcode;
  unsigned char memory[4096];
  unsigned char V[16];

  unsigned short I;
  unsigned short pc;

  unsigned char gfx[64 * 32];

  unsigned char delay_timer;
  unsigned char sound_timer;

  unsigned short stack[16];
  unsigned short sp;

  unsigned char key[16];

  public:
    bool draw_flag;
    void init();
    void emulate_cycle();
};
