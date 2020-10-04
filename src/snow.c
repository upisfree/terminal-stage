void renderPixel(int x, int y, char symbol);

const int rainCount = 25;
float rainXs[rainCount];
float rainYs[rainCount];

void generateRain() {
  for (int i = 0; i < rainCount; i++) {
    rainXs[i] = randomRangeInt(0, WINDOW_WIDTH);
    rainYs[i] = randomRangeInt(0, WINDOW_HEIGHT);
  }
}

void renderRain() {
  for (int i = 0; i < rainCount; i++) {
    float x = rainXs[i];
    float y = rainYs[i];

    x += randomRangeInt(-1, 1);
    y += 1;

    if (x < 0 || x > WINDOW_WIDTH) {
      x = randomRangeInt(0, WINDOW_WIDTH);
    }

    if (y > WINDOW_HEIGHT) {
      y = 0;
      x = randomRangeInt(0, WINDOW_WIDTH);
    }

    renderPixel(x, y, POST_RAIN);

    rainXs[i] = x;
    rainYs[i] = y;
  }
}