extern const int RECTS_COUNT;
extern const int NPCS_COUNT;
extern char* DEBUG_INFO;
extern Player player;
extern NPC npcs[];
extern Rectangle rects[];

bool isRectanglesCollide(Rectangle *r1, Rectangle *r2) {
  float r1x = r1->position.x;
  float r1y = r1->position.y;
  float r1w = r1->size.x;
  float r1h = r1->size.y;

  float r2x = r2->position.x;
  float r2y = r2->position.y;
  float r2w = r2->size.x;
  float r2h = r2->size.y;

  if (
    (
      (r1x < r2x + r2w && r1x + r1w > r2x + r2w) || (r1x < r2x && r1x + r1w > r2x)
    )
    &&
    (
      (r1y < r2y && r2y < r1y + r1h) || (r1y + r1h > r2y + r2h && r1y < r2y + r2h)
    )
  ) {
    return true;
  } else {
    return false;
  }
}

bool isVectorsCollide(Vector2 *v1, Vector2 *v2) {
  float v1x = v1->x;
  float v1y = v1->y;

  float v2x = v2->x;
  float v2y = v2->y;

  if (v1x == v2x && v1y == v2y) {
    return true;
  } else {
    return false;
  }
}

bool isVectorAndRectangleCollide(Vector2 *v, Rectangle *r) {
  // Rectangle rv = {
  //   .position = { v->x, v->y },
  //   .size = { 1.0f, 1.0f },
  //   .symbol = 'a'
  // };

  return (v->x > r->position.x && v->x < (r->position.x + r->size.x)) && (v->y > r->position.y && v->y < (r->position.y + r->size.x));

  // return isRectanglesCollide(r, &rv);
}

bool isPositionOutOfBounds(int x, int y) {
  return x < 0 || x > WINDOW_WIDTH - 1 || y < 0 || y > WINDOW_HEIGHT - 1;
}

bool isVectorOutOfBounds(Vector2 *v) {
  return v->x < 0 || v->x > WINDOW_WIDTH - 1 || v->y < 0 || v->y > WINDOW_HEIGHT;
}

void updateNPCs() {
  for (int i = 0; i < NPCS_COUNT; i++) {
    Vector2 collisionVector = {
      round(npcs[i].position.x + npcs[i].speed * cos(npcs[i].rotation)),
      round(npcs[i].position.y + npcs[i].speed * sin(npcs[i].rotation))
    };

    // чет не работает
    for (int j = 0; j < RECTS_COUNT; j++) {
      if (isVectorAndRectangleCollide(&collisionVector, &rects[i])) {
        npcs[i].rotation += PI;
        // npcs[i].rotation *= -1.0f;

        DEBUG_INFO = "collision: true\n";

        // break;
      } else {
        DEBUG_INFO = "collision: false\n";
      }
    }

    if (isVectorOutOfBounds(&collisionVector)) {
      npcs[i].rotation += PI;
      // npcs[i].rotation += PI / 2;

      // if (npcs[i].rotation > PI * 2) {
      //   npcs[i].rotation = 0.0f;
      // }
    }

    npcs[i].position.x = round(npcs[i].position.x + npcs[i].speed * cos(npcs[i].rotation));
    npcs[i].position.y = round(npcs[i].position.y + npcs[i].speed * sin(npcs[i].rotation));
  }
}

void updatePhysics() {
  updateNPCs();
}