const MAP_WIDTH = 256;
const MAP_HEIGHT = 256;
let map = '';

for (let i = 0; i < MAP_WIDTH * MAP_HEIGHT; i++) {
  if (i % MAP_WIDTH === 0) {
    map += '\n';
  }

  map += (Math.random() > 0.99) ? 'o' : ' ';
}

map = map.substring(1);

copy(map);