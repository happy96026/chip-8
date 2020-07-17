#pragma once

class Chip8 {
  unsigned short opcode;
  unsigned char memory[4096];
  unsigned char V[16];

  unsigned short index;
  unsigned short pc;

  unsigned char gfx[64 * 32];

  unsigned char delayTimer;
  unsigned char soundTimer;

  unsigned short stack[16];
  unsigned short sp;

  unsigned char key[16];

  public:
    bool drawFlag;
    void initialize();
    void emulateCycle();
};
