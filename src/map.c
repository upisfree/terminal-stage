#include <stdio.h>
#include <stdlib.h>

const int MAP_WIDTH = 256;
const int MAP_HEIGHT = 256;

char *mapBuffer = NULL;

void readMapFromFile(char *path) {
  FILE *fh = fopen(path, "rb");
  
  if (fh != NULL) {
    fseek(fh, 0L, SEEK_END);
    long s = ftell(fh);
    rewind(fh);
    mapBuffer = malloc(s);

    if (mapBuffer != NULL) {
      fread(mapBuffer, s, 1, fh);
      fclose(fh);
      fh = NULL;

      // free(mapBuffer);
    }

    if (fh != NULL) {
      fclose(fh);
    }
  }
}

void generateEmptyMap() {
  // выделяем память под строку
  mapBuffer = malloc(MAP_WIDTH * MAP_HEIGHT);

  for (int i = 0; i < MAP_WIDTH * MAP_HEIGHT; i++) {
    mapBuffer[i] = BLOCK_AIR;
  }
}

void generateRandomMap() {
  // выделяем память под строку
  mapBuffer = malloc(MAP_WIDTH * MAP_HEIGHT);

  for (int i = 0; i < MAP_WIDTH * MAP_HEIGHT; i++) {
    mapBuffer[i] = (randomRangeInt(1, 100) == 99) ? BLOCK_STONE : BLOCK_AIR;
  }
}

void generatePerlinNoiseMap(float freq, int depth) {
  // выделяем память под строку
  mapBuffer = malloc(MAP_WIDTH * MAP_HEIGHT);

  for (int x = 0; x < MAP_WIDTH; x++) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
      int i = (y * MAP_WIDTH) + x; // я знаю, что можно без двойного цикла сделать, иди нахуй)
      float v = perlin2d(x, y, freq, depth);
      char s;

      if (v > 0.5) {
        s = BLOCK_STONE;
      } else {
        s = BLOCK_AIR;
      }

      mapBuffer[i] = s;
    }
  }
}

void removeChars(char *s, char c) {
  int writer = 0, reader = 0;

  while (s[reader]) {
    if (s[reader] != c) {   
      s[writer++] = s[reader];
    }

    reader++;
  }

  s[writer] = 0;
}

char getCharFromMap(int x, int y) {
  if (x > MAP_WIDTH - 1) {
    x = MAP_WIDTH - 1;
  }

  if (y > MAP_HEIGHT - 1) {
    y = MAP_HEIGHT - 1;
  }

  int i = (y * MAP_WIDTH) + x;

  return mapBuffer[i];
}

void setCharToMap(int x, int y, char symbol) {
  if (x > MAP_WIDTH - 1) {
    x = MAP_WIDTH - 1;
  }

  if (y > MAP_HEIGHT - 1) {
    y = MAP_HEIGHT - 1;
  }

  int i = (y * MAP_WIDTH) + x;

  mapBuffer[i] = symbol;
}

bool isXYOutOfMap(int x, int y) {
  return x < 0 ||
         x > MAP_WIDTH - 1 ||
         y < 0 ||
         y > MAP_HEIGHT - 1;
}

// TODO: enum блоков
bool isSolidBlock(int x, int y) {
  char c = getCharFromMap(x, y);

  switch (c) {
    case BLOCK_STONE:
    // case '.':
      return true;

    case BLOCK_AIR:
      return false;

    default:
      // return true;
      return false;
  }
}

bool isAirBlock(int x, int y) {
  char c = getCharFromMap(x, y);

  if (c == BLOCK_AIR) {
  // if (c == BLOCK.AIR) {
    return true;
  } else {
    return false;
  }
}

void setCircleToMap(int x0, int y0, int length, float angleStep, char symbol) {
  int x = x0;
  int y = y0;

  float angle = 0.0;

  while (angle < 2 * PI) {
    x = x0 + length * cos(angle);
    y = y0 + length * sin(angle) / 2; // см. коммент к bool isPointInCircleHalfY

    setCharToMap(x, y, symbol);

    angle += angleStep;
  }
}