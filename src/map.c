#include <stdio.h>
#include <stdlib.h>

const int MAP_WIDTH = 256;
const int MAP_HEIGHT = 256;

// enum BLOCK = {
//   AIR = ' ',
//   STONE = 'о',
//   // WOOD = '.', // песок?
// };

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

void generateRandomMap() {
  // выделяем память под строку
  mapBuffer = malloc(MAP_WIDTH * MAP_HEIGHT);

  for (int i = 0; i < MAP_WIDTH * MAP_HEIGHT; i++) {
    mapBuffer[i] = (randomRangeInt(1, 100) == 99) ? 'o' : ' ';
  }
}

void generatePerlinNoiseMap() {
  // выделяем память под строку
  mapBuffer = malloc(MAP_WIDTH * MAP_HEIGHT);

  for (int x = 0; x < MAP_WIDTH; x++) {
    for (int y = 0; y < MAP_HEIGHT; y++) {
      int i = (y * MAP_WIDTH) + x; // я знаю, что можно без двойного цикла сделать, иди нахуй)
      float v = perlin2d(x, y, 0.05, 4);
      char s;

      if (v > 0.5) {
        s = 'o';
      } else {
        s = ' ';
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

void setCharToMap(int x, int y, char s) {
  if (x > MAP_WIDTH - 1) {
    x = MAP_WIDTH - 1;
  }

  if (y > MAP_HEIGHT - 1) {
    y = MAP_HEIGHT - 1;
  }

  int i = (y * MAP_WIDTH) + x;

  mapBuffer[i] = s;
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
    case 'o':
    case '.':
      return true;

    case ' ':
      return false;

    default:
      // return true;
      return false;
  }
}

bool isAirBlock(int x, int y) {
  char c = getCharFromMap(x, y);

  if (c == ' ') {
  // if (c == BLOCK.AIR) {
    return true;
  } else {
    return false;
  }
}