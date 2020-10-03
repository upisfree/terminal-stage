// Каркас этого файла написал Вася Эдомин.

// typedef struct {
//     char *name;
//     int step;
// } PostEffect;

// typedef struct {
//     PostEffect postEffect;
//     Vector2 position;
//     float intense;
// } ExplosionPostEffect;

/* Максимальная длина имени функции */
#define FUNC_NAME_MAX 64
/* Максимальное количество активных постэффектов */
#define POST_EFFECTS_MAX 64

/* Функция постэффекта */
typedef void (*PostEffectFunction)(void *);
/* Аргументы постэффекта - просто 256 байт */
typedef char PostEffectArgs[256];

/* структура, которая хранит имя постэффекта и функцию постэффекта, соответствующую имени */
typedef struct {
  char name[FUNC_NAME_MAX];
  PostEffectFunction function;
} PostEffectNamedFunc;

/* Элемент списка активных постэффектов */
typedef struct {
  char name[FUNC_NAME_MAX];
  PostEffectArgs args;
} PostEffectsListEntry;

/* Список активных постэффектов */
typedef struct {
  int count;
  PostEffectsListEntry entries[POST_EFFECTS_MAX];
} PostEffectsList;

/* Аргументы для постэффекта взрыва */
typedef struct {
  int radius;
  uint32_t color;
} ExplosionArgs;

/* Аргументы для постэффекта сияния */
typedef struct {
  int radius;
  uint32_t color;
  uint8_t alpha;
} GlowArgs;

void RenderExplosion(void *args);
void RenderGlow(void *args);

/* Массив, в котором хранятся имена и функции постэффектов */
PostEffectNamedFunc PostEffectNamedFunctionsList[] = {
  {.name = "explosion", .function = RenderExplosion},
  {.name = "glow", .function = RenderGlow},
  /* etc */
};

/* Число элементов в массиве выше */
int PostEffectNamedFunctionsCount = 2;

/* Инициализация списка постэффектов. Список должен быть объявлен вне этой функции */
void initPostEffectsList(PostEffectsList *postEffectsList) {
  if (postEffectsList == NULL) {
    return;    
  }

  postEffectsList->count = 0;
}

/* Добавление взрыва в список активных постэффектов. Придумай сам, как ты будешь добавлять взрыв в список постэффектов. Это просто пример */
void AddPostEffectExplosion(PostEffectsList *postEffectsList, int radius, uint32_t color) {
  ExplosionArgs *explosionArgs = (ExplosionArgs *)postEffectsList->entries[postEffectsList->count].args;

  postEffectsList->entries[postEffectsList->count].name = "explosion";
  explosionArgs.radius = radius;
  explosionArgs.color = color;

  postEffectsList->count++;
}

/* Добавление сияния в список активных постэффектов. */
void AddPostEffectGlow(PostEffectsList *postEffectsList, int radius, uint32_t color, uint8_t alpha) {
  GlowArgs *glowArgs = (GlowArgs *)postEffectsList->entries[postEffectsList->count].args;

  postEffectsList->entries[postEffectsList->count].name = "glow";
  glowArgs.radius = radius;
  glowArgs.color = color;
  glowArgs.alpha = alpha;

  postEffectsList->count++;
}

/* Эта функция постэффекта взрыва */
void RenderExplosion(void *args) {
  // ExplosionArgs *explosionArgs = (ExplosionArgs *)args;

  // RenderCircle(explosionArgs.radius, explosionArgs.color);
}

/* Эта функция постэффекта сияния */
void RenderGlow(void *args) {
  // GlowArgs *glowArgs = (GlowArgs *)args;

  // RenderTransparentCircle(glowArgs.radius, glowArgs.color, glowArgs.alpha);
}

/* Это функция, ктороая возвращает функцию постэффекта */
PostEffectFunction PostEffectNameToFunction(char *name) {
  for (int i = 0; i < PostEffectNamedFunctionsCount; i++) {
    if (strcmp(name, PostEffectNamedFunctionsList[i].name) == 0) {
      return PostEffectNamedFunctionsList[i].function;
    }
  }

  return NULL;
}

void RenderPostEffect(PostEffectsList *postEffectsList) {
  /* Вытаскиваем первый постэффект и вызываем его функцию с аргументами. Придумай сам, как проходить по списку активных постэффектов */
  PostEffectFunction function = PostEffectNameToFunction(postEffectsList->entries[0].name);
  /* Вызываем функцию первого постэффекта с аргументами */
  function(&postEffectsList->entries[0].args);
}
