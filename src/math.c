#include <string.h>

#define PI 3.14159265358979323846f

typedef struct Vector2 {
  float x;
  float y;
} Vector2;

typedef struct Rectangle {
  Vector2 position;
  Vector2 size;
  char symbol;
} Rectangle;

// // возвращает нормализованный угол в радианах между (0 — PI × 2)
// export function normalize(a: number): number {
//   return a - Angle.PI_2 * Math.floor(a / Angle.PI_2);
// }

int randomRangeInt(int min, int max) {
  return min + rand() % (max + 1 - min);
}

float randomRangeFloat(float min, float max) {
  float scale = rand() / (float)RAND_MAX;

  return min + scale * (max - min);
}

// concat strings
char* concat(const char *s1, const char *s2) {
  char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
  // in real code you would check for errors in malloc here
  strcpy(result, s1);
  strcat(result, s2);

  return result;
}

// char* floatToString(float a) {
//   char array[10];
//   sprintf(array, "%f", a);

//   return array;
// }
