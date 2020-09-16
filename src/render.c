extern Player player;
extern Rectangle rects[];
extern NPC npcs[];

// TOOD: dynamic
extern const int NPCS_COUNT;
extern char* DEBUG_INFO;



void renderPixel(int x, int y, char symbol) {
  if (isPositionOutOfBounds(x, y)) {
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

void renderPlayer() {
  renderPixel(player.position.x, player.position.y, player.symbol);
}

void renderDebugInfo() {
  char* text =
    "terminal stage\n";
    // "";

  text = concat(text, DEBUG_INFO);

  char x[64];
  sprintf(x, "%f", npcs[0].position.x);
  char y[64];
  sprintf(y, "%f", npcs[0].position.y);
  char r[64];
  sprintf(r, "%f", npcs[0].rotation);
  text = concat(text, x);
  text = concat(text, ", ");
  text = concat(text, y);
  text = concat(text, "\n");
  text = concat(text, r);

  move(0, 0);
  printw("%s", text);

  // free(text);
}

void render() {
  clear();

  for (int i = 0; i < RECTS_COUNT; i++) {
    renderRectangle(&rects[i]);
  }

  renderNPCs();
  // renderPlayer();
  renderDebugInfo();

  refresh();
}