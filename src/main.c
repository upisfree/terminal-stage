#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include "math.c"
#include "structs.c"
#include "keyboard.c"
#include "physics.c"
#include "render.c"
#include "level.c"

const int SEED = 1488;
const int RECTS_COUNT = 2;
const int NPCS_COUNT = 40;

WINDOW *window;
int WINDOW_WIDTH;
int WINDOW_HEIGHT;

Player player = {
  .position = { 10, 10 },
  .speed = 2,
  .symbol = 'o'
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

  generateRectangles();
  generateNPCs();

  while (1) {
    WINDOW_WIDTH = COLS;
    WINDOW_HEIGHT = LINES;

    updatePhysics();
    render();

    updateKeyboard();
  }

  endwin();

  return 0;
}