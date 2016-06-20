/* github.com/rubicks/libmorton/test/impl.c */

#include <assert.h>
/* #include <limits.h> */
/* #include <stdint.h> */
/* #include <stdio.h> */
/* #include <stdlib.h> */

#include "morton.c"

int
main(int argc, char** argv)
{
  (void)argc;
  (void)argv;

  for (unsigned v = 0; v < 256; ++v) {
    assert(_encode(v << 0 * CHAR_BIT) == _expand(v) << 0);
    assert(_encode(v << 1 * CHAR_BIT) == _expand(v) << 1);
    assert(_encode(v << 2 * CHAR_BIT) == _expand(v) << 2);
  }

  for (unsigned v = 0; v < 256; ++v) {
    assert(_p30[v] == _expand(v));
    assert(v == _shrink(_p30[v]));
  }

  for (unsigned v = 0; v < 0x1000000; ++v) {
    assert(v == _decode(_encode(v)));
  }

  return EXIT_SUCCESS;
}
