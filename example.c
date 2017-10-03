#include <stdio.h>
#include "unitsy.h"

unitsy_init;

int test_inequality_fails() {
  unitsy_assert(3==4, "Equality is false");
  return 0;
}

int test_equality_works() {
  unitsy_assert(3==3, "Equality is false");
  return 0;
}

int main(int argc, const char *argv[]) {
  unitsy_run(test_inequality_fails);
  unitsy_run(test_equality_works);
  printf("%d/%d\n", unitsy->passed_tests, unitsy->total_tests);
  return unitsy->result;
}

