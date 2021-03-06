#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ncurses.h>
#include "symbols.c"
#include "math/noise.c"
#include "math.c"
#include "structs.c"
// #include "post.c"
#include "map.c"
#include "physics.c"
#include "keyboard.c"
#include "render.c"
#include "level.c"
#include "snow.c"

const int SEED = 2048;
const int RECTS_COUNT = 2;
const int NPCS_COUNT = 40;

WINDOW *window;
int WINDOW_WIDTH;
int WINDOW_HEIGHT;

Player player = {
  .position = { 256 / 2, 256 / 2 },
  .speed = 2,
  .symbol = BLOCK_PLAYER
};

Rectangle rects[RECTS_COUNT];
NPC npcs[NPCS_COUNT];

char* DEBUG_INFO = "\n";

int main() {
  srand(time(NULL));
  // srand(SEED);

  window = initscr();
  keypad(stdscr, true);
  curs_set(0);
  noecho();
  halfdelay(1); // 100 ms

  WINDOW_WIDTH = COLS;
  WINDOW_HEIGHT = LINES;

  // generateRandomMap();
  // readMapFromFile("./map");
  // removeChars(mapBuffer, '\n');

  // generateRectangles();
  // generateNPCs();

  // initPostEffectsList(&activePostEffectsList);

  generateRain();

  generateEmptyMap();
  // generatePerlinNoiseMap(0.05, 4);

  // float freq = 0.05;
  // float depth = 4;

  while (1) {
    WINDOW_WIDTH = COLS;
    WINDOW_HEIGHT = LINES;

    // generatePerlinNoiseMap(freq, depth);
    // freq += cos(time(NULL)) / 20000;
    // depth += cos(time(NULL));

    // updatePhysics();
    render();

    updateKeyboard();
  }

  endwin();

  return 0;
}