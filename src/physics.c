extern const int RECTS_COUNT;
extern const int NPCS_COUNT;
extern char* DEBUG_INFO;
extern Player player;
extern NPC npcs[];
extern Rectangle rects[];

void updatePhysics() {
  // updateNPCs();
}

void explosion(int x0, int y0, float r) {
  int ir = round(r);

  for (int x = x0 - ir; x < x0 + r * 2; x++) {
    for (int y = y0 - ir; y < y0 + r * 2; y++) {
      if (isXYOutOfMap(x, y)) {
        continue;
      }

      if (isPointInCircleHalfY(x, y, x0, y0, r)) {
        setCharToMap(x, y, BLOCK_AIR);
      }
    }
  }

  // cvector_push_back(postEffects, 10);

  // setCircleToMap(x0, y0, ir, 0.1, '-');
}