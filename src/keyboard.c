extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;

extern Player player;

const int KEY_W = 119;
const int KEY_A = 97;
const int KEY_S = 115;
const int KEY_D = 100;
const int KEY_C = 99;

// TODO: на русской раскладе почему-то в три раза больше событий падает
void updateKeyboard() {
  int code = getch();

  switch (code) {
    case KEY_UP:
    case KEY_W:
      if (isAirBlock(player.position.x, player.position.y - player.speed)) {
        player.position.y -= player.speed;
      }

      break;
    
    case KEY_DOWN:
    case KEY_S:
      if (isAirBlock(player.position.x, player.position.y + player.speed)) {
        player.position.y += player.speed;
      }

      break;

    case KEY_LEFT:
    case KEY_A:
      if (isAirBlock(player.position.x - player.speed, player.position.y)) {
        player.position.x -= player.speed;
      }

      break;
      
    case KEY_RIGHT:
    case KEY_D:
      if (isAirBlock(player.position.x + player.speed, player.position.y)) {
        player.position.x += player.speed;
      }

      break;

    case KEY_C:
      explosion(player.position.x, player.position.y, 10.0f);

      break;
  }

  if (player.position.x < 0) {
    player.position.x = 0;
  }

  if (player.position.x > MAP_WIDTH - 1) {
    player.position.x = MAP_WIDTH - 1;
  }

  if (player.position.y < 0) {
    player.position.y = 0;
  }

  if (player.position.y > MAP_HEIGHT - 1) {
    player.position.y = MAP_HEIGHT - 1;
  }
}
