extern Player player;
extern Rectangle rects[];
extern NPC npcs[];

// TOOD: dynamic
extern const int NPCS_COUNT;
extern char* DEBUG_INFO;

bool isXYOutOfWindow(int x, int y) {
  return x < 0 ||
         x > WINDOW_WIDTH - 1 ||
         y < 0 ||
         y > WINDOW_HEIGHT - 1;
}

void renderPixel(int x, int y, char symbol) {
  if (isXYOutOfWindow(x, y)) {
    return;
  }

  move(y, x);
  printw("%c", symbol);
}

void renderRectangle(Rectangle *rect) {
  for (int x = 0; x < rect->size.x; x++) {
    for (int y = 0; y < rect->size.y; y++) {
      renderPixel(rect->position.x + x, rect->position.y + y, rect->symbol);
    }
  }
}

void renderNPCs() {
  for (int i = 0; i < NPCS_COUNT; i++) {
    renderPixel(npcs[i].position.x, npcs[i].position.y, npcs[i].symbol);
  }
}

void renderMap() {
  // система координат карты
  int playerX = player.position.x;
  int playerY = player.position.y;

  // система координат экрана
  int halfWidth = round(WINDOW_WIDTH / 2);
  int halfHeight = round(WINDOW_HEIGHT / 2);

  for (int screenX = 0; screenX < WINDOW_WIDTH; screenX++) {
    for (int screenY = 0; screenY < WINDOW_HEIGHT; screenY++) {
      int blockX = playerX - halfWidth + screenX;
      int blockY = playerY - halfHeight + screenY;

      if (isXYOutOfMap(blockX, blockY) == false) {
        renderPixel(screenX, screenY, getCharFromMap(blockX, blockY));
      } else {
        renderPixel(screenX, screenY, (randomRangeInt(0, 1) == 1 ? '-' : '~'));
      }
    }
  }
}

void renderPlayer() {
  int x = round(WINDOW_WIDTH / 2);
  int y = round(WINDOW_HEIGHT / 2);

  renderPixel(x, y, player.symbol);
  // renderPixel(player.position.x, player.position.y, player.symbol);
}

void renderDebugInfo() {
  move(0, 0);
  printw("%s", "terminal stage");

  move(1, 0);
  printw("%i, %i", (int)player.position.x, (int)player.position.y);

  // text = concat(text, DEBUG_INFO);
}

void render() {
  clear();

  // for (int i = 0; i < RECTS_COUNT; i++) {
  //   renderRectangle(&rects[i]);
  // }

  renderMap();
  // renderNPCs();
  renderPlayer();

  renderDebugInfo();

  refresh();
}