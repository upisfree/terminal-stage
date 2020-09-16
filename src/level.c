extern const int RECTS_COUNT;
extern const int NPCS_COUNT;
extern Rectangle rects[];
extern NPC npcs[];

void generateRectangles() {
  for (int i = 0; i < RECTS_COUNT; i++) {
    Rectangle rect = {
      // .position = { 10, 10 },
      .position = { randomRangeInt(0, WINDOW_WIDTH), randomRangeInt(0, WINDOW_HEIGHT) },
      // .size = { 40, 20 },
      .size = { randomRangeInt(4, 20), randomRangeInt(8, 10) },
      .symbol = 'a'
    };

    rects[i] = rect;
  }
}

void generateNPCs() {
  for (int i = 0; i < NPCS_COUNT; i++) {
    NPC npc = {
      // .position = { 60, 20 },
      .position = { randomRangeInt(0, WINDOW_WIDTH), randomRangeInt(0, WINDOW_HEIGHT) },
      // .speed = 0.75f,
      .speed = randomRangeFloat(1, 2),
      // .rotation = PI,
      .rotation = randomRangeFloat(0, PI * 2),
      .symbol = 'q'
    };

    npcs[i] = npc;
  }
}
