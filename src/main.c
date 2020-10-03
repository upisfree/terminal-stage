#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ncurses.h>
#include "lib/cvector.h"
#include "blocks.c"
#include "math/noise.c"
#include "math.c"
#include "structs.c"
#include "post.c"
#include "map.c"
#include "physics.c"
#include "keyboard.c"
#include "render.c"
#include "level.c"

const int SEED = 2048;
const int RECTS_COUNT = 2;
const int NPCS_COUNT = 40;

WINDOW *window;
int WINDOW_WIDTH;
int WINDOW_HEIGHT;

Player player = {
  .position = { 256 / 2, 256 / 2 },
  .speed = 2,
  .symbol = 'M'
};

Rectangle rects[RECTS_COUNT];
NPC npcs[NPCS_COUNT];

PostEffectsList activePostEffectsList;

cvector_vector_type(PostEffect) postEffects = NULL;

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

  // printw("%c\n", mapBuffer[0]);
  // printw("%c\n", getCharFromMap(0, 1));
  // printw("%c\n", getCharFromMap(255, 0));

  initPostEffectsList(&activePostEffectsList);

  float freq = 0.05;
  float depth = 4;

  while (1) {
    WINDOW_WIDTH = COLS;
    WINDOW_HEIGHT = LINES;

    generatePerlinNoiseMap(freq, depth);
    freq += cos(time(NULL)) / 20000;
    // depth += cos(time(NULL));

    // updatePhysics();
    render();

    updateKeyboard();
  }

  endwin();

  return 0;
}