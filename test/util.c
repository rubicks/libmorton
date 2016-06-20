/* github.com/rubicks/libmorton/test/util.c */

#include <assert.h>
#include <stdlib.h>

#include "binlit.h"
#include "util.h"

int
main(int argc, char** argv)
{
  (void)argc;
  (void)argv;

  assert(B8(101010) == 42);
  assert(B8(101001) == 41);
  assert(B8(100101) == 37);
  assert(B8(100011) == 35);

  assert(util_cardinality(B8(101010)) == 3);
  assert(util_cardinality(B8(101001)) == 3);
  assert(util_cardinality(B8(100101)) == 3);
  assert(util_cardinality(B8(100011)) == 3);

  assert(util_floor2(B8(101010)) == B8(100000));
  assert(util_floor2(B8(101001)) == B8(100000));
  assert(util_floor2(B8(100101)) == B8(100000));
  assert(util_floor2(B8(100011)) == B8(100000));

  assert(B8(11111111) == 0xff);
  assert(B32(00000000, 00100100, 10010010, 01001001) == 0x249249);

  assert(util_part3(B8(11111111)) ==
         B32(00000000, 00100100, 10010010, 01001001));

  return EXIT_SUCCESS;
}
