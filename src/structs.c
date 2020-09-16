typedef struct Player {
  Vector2 position;
  int speed;
  char symbol;
} Player;

typedef struct NPC {
  Vector2 position;
  float speed;
  float rotation; // in rads
  char symbol;
} NPC;