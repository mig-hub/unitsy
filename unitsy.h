typedef struct unitsy_env_t {
  int passed_tests;
  int total_tests;
  int result;
} unitsy_env_t;

#define unitsy_assert(test, message) do { \
  if (!(test)) { \
    printf("%s:%d:%s %s\n\n", __FILE__, __LINE__, __func__, message); \
    unitsy->result = 1; \
    return 1; \
  } \
} while (0)

#define unitsy_run(test) do { \
  int result = test(); \
  unitsy->total_tests++; \
  if (result==0) unitsy->passed_tests++; \
} while (0)


#define unitsy_init unitsy_env_t unitsy_env = {0,0,0}; unitsy_env_t * unitsy = &unitsy_env;

