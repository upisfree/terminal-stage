extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT;

extern Player player;

const int KEY_W = 119;
const int KEY_A = 97;
const int KEY_S = 115;
const int KEY_D = 100;

// TODO: на русской раскладе почему-то в три раза больше событий падает
void updateKeyboard() {
  int code = getch();

  switch (code) {
    case KEY_UP:
    case KEY_W:
      player.position.y -= player.speed;

      break;
    
    case KEY_DOWN:
    case KEY_S:
      player.position.y += player.speed;

      break;

    case KEY_LEFT:
    case KEY_A:
      player.position.x -= player.speed;

      break;
      
    case KEY_RIGHT:
    case KEY_D:
      player.position.x += player.speed;

      break;
  }

  if (player.position.x < 0) {
    player.position.x = 0;
  }

  if (player.position.x >= WINDOW_WIDTH - 1) {
    player.position.x = WINDOW_WIDTH - 1;
  }

  if (player.position.y < 0) {
    player.position.y = 0;
  }

  if (player.position.y >= WINDOW_HEIGHT - 1) {
    player.position.y = WINDOW_HEIGHT - 1;
  }
}
