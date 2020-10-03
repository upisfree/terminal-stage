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

typedef struct PostEffect {
  char* name;
  int step;
} PostEffect;

typedef struct ExplosionPostEffect {
  PostEffect effect;
  Vector2 position;
  float intense;
} ExplosionPostEffect;