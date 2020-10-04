void renderPixel(int x, int y, char symbol);

const int snowCount = 25;
float snowXs[snowCount];
float snowYs[snowCount];

void generateSnow() {
  for (int i = 0; i < snowCount; i++) {
    snowXs[i] = randomRangeInt(0, WINDOW_WIDTH);
    snowYs[i] = randomRangeInt(0, WINDOW_HEIGHT);
  }
}

void renderSnow() {
  for (int i = 0; i < snowCount; i++) {
    float x = snowXs[i];
    float y = snowYs[i];

    x += randomRangeInt(-1, 1);
    y += 0.5;

    if (x < 0 || x > WINDOW_WIDTH) {
      x = randomRangeInt(0, WINDOW_WIDTH);
    }

    if (y > WINDOW_HEIGHT) {
      y = 0;
      x = randomRangeInt(0, WINDOW_WIDTH);
    }

    renderPixel(x, y, POST_SNOW);

    snowXs[i] = x;
    snowYs[i] = y;
  }
}