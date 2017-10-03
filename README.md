Unitsy
======

Unitsy is a set of macros for unit testing in C.

Just copy the `unitsy.h` file in your project and then include 
it in your test file. Then initialize with `unitsy_init`.

```c
#include "unitsy.h"

unitsy_init;
```

Each test function takes no argument and returns an `int`.
0 means it passed and 1 means it failed. You would use `unitsy_assert` to 
register your assertions and return 0 at the hand to make sure it returns this
when no assertion has failed.

```c
int test_one_plus_one_makes_two() {
  int cumul = 1 + 1;
  unitsy_assert(cumul==2, "1+1 does not make 2");
  return 0;
}
```

In order to run tests, you have to use `unitsy_run` in your main function 
for each test. Then you can use the values collected in the `unitsy` object 
to build your report.

```c
int main(int argc, const char *argv[]) {
  unitsy_run(test_one_plus_one_makes_two);
  /* more tests */
  printf("%d/%d\n", unitsy->passed_tests, unitsy->total_tests);
  return unitsy->result;
}
```

Check the file `example.c` if you want to see a full example.

```bash
$ make example
$ ./example
```

