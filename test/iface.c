/* github.com/rubicks/libmorton/test/iface.c */

#include <assert.h>
#include <inttypes.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "binlit.h"
#include "morton.h"
#include "util.h"

int
main(int argc, char** argv)
{
  (void)argc;
  (void)argv;

  assert(32 == util_floor2(42));

  assert(B8(1) == 1);
  assert(B8(10) == 2);
  assert(B8(100) == 4);
  assert(B8(1000) == 8);
  assert(B8(10000) == 16);
  assert(B8(100000) == 32);
  assert(B8(1000000) == 64);

  assert(3 == util_cardinality(42));
  assert(3 == util_cardinality(41));
  assert(3 == util_cardinality(37));
  assert(3 == util_cardinality(35));

  for (unsigned v = 0; v < 256; ++v) {
    assert(morton_encode(v << 0 * CHAR_BIT) == morton_expand(v) << 0);
    assert(morton_encode(v << 1 * CHAR_BIT) == morton_expand(v) << 1);
    assert(morton_encode(v << 2 * CHAR_BIT) == morton_expand(v) << 2);
  }

  assert(0x249249 == util_part3(0xff));

  for (unsigned v = 0; v < 0x1000000; ++v) {
    assert(morton_decode(morton_encode(v)) == v);
  }

  assert(B24(00000000, 00000000, 00000000) ==
         morton_encode(B24(00000000, 00000000, 00000000)));
  assert(B24(00000000, 00000010, 01001001) ==
         morton_encode(B24(00000000, 00000000, 00001111)));
  assert(B24(00100100, 10010000, 00000000) ==
         morton_encode(B24(00000000, 00000000, 11110000)));
  assert(B24(00100100, 10010010, 01001001) ==
         morton_encode(B24(00000000, 00000000, 11111111)));

  assert(B24(00000000, 00000100, 10010010) ==
         morton_encode(B24(00000000, 00001111, 00000000)));
  assert(B24(00000000, 00000110, 11011011) ==
         morton_encode(B24(00000000, 00001111, 00001111)));
  assert(B24(00100100, 10010100, 10010010) ==
         morton_encode(B24(00000000, 00001111, 11110000)));
  assert(B24(00100100, 10010110, 11011011) ==
         morton_encode(B24(00000000, 00001111, 11111111)));

  assert(B24(01001001, 00100100, 10010010) ==
         morton_encode(B24(00000000, 11111111, 00000000)));
  assert(B24(01101101, 10110110, 11011011) ==
         morton_encode(B24(00000000, 11111111, 11111111)));

  assert(B24(10010010, 01001001, 00100100) ==
         morton_encode(B24(11111111, 00000000, 00000000)));
  assert(B24(10110110, 11011011, 01101101) ==
         morton_encode(B24(11111111, 00000000, 11111111)));
  assert(B24(11011011, 01101101, 10110110) ==
         morton_encode(B24(11111111, 11111111, 00000000)));

  assert(B24(11111111, 11111111, 11111111) ==
         morton_encode(B24(11111111, 11111111, 11111111)));

  return EXIT_SUCCESS;
}
