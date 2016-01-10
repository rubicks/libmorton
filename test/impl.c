/* github.com/rubicks/libmorton/test/impl.c */

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "morton.c"

/* returns the largest power of two that does not exceed the given number */
unsigned long
_floor2(unsigned long v)
{
  unsigned long ret;
  do {
    ret = v;
  } while (v &= v - 1);
  return ret;
}

unsigned long
_cardinality(unsigned long v)
{
  unsigned long c = 0;
  for (; v; ++c) v &= v - 1;
  return c;
}

unsigned
_part3(unsigned v)
{
  v &= 0xffffff;
  v = (v | (v << 16)) & (unsigned)0x0000ff;
  v = (v | (v << 8)) & (unsigned)0x00f00f;
  v = (v | (v << 4)) & (unsigned)0x0c30c3;
  v = (v | (v << 2)) & (unsigned)0x249249;
  return v;
}

#define N_BITS(v) (sizeof(v) * CHAR_BIT)

int
main(int argc, char** argv)
{
  for (int i = 0; i < argc; ++i) {
    printf("argv[%d] == \"%s\"", i, argv[i]);
  }
#if 0
  assert(0 == 000_b);
  assert(1 == 001_b);
  assert(2 == 010_b);
  assert(3 == 011_b);
  assert(4 == 100_b);
  assert(5 == 101_b);
  assert(6 == 110_b);
  assert(7 == 111_b);

  assert(32 == 100000_b);
  assert(42 == 101010_b);
  assert(100000_b == _floor2(101010_b));
#endif
  assert(32 == _floor2(42));

#if 0
  assert(3 == _cardinality(101010_b));
  assert(3 == _cardinality(101001_b));
  assert(3 == _cardinality(100101_b));
  assert(3 == _cardinality(100011_b));
#endif
  assert(3 == _cardinality(42));
  assert(3 == _cardinality(41));
  assert(3 == _cardinality(37));
  assert(3 == _cardinality(35));

#if 0
  assert("111b" == _bitstr(7));
  assert("101010b" == _bitstr(42));
  assert("11110000111100001111b" == _bitstr(0x0f0f0f));

  assert("11111111b" == _bitstr(0x0000ff));
  assert("1111000000001111b" == _bitstr(0x00f00f));
  assert("11000011000011000011b" == _bitstr(0x0c30c3));
  assert("1001001001001001001001b" == _bitstr(0x249249));
#endif

  for (unsigned v = 0; v < 256; ++v) {
    assert(morton_encode(v << 0 * CHAR_BIT) == morton_expand(v) << 0);
    assert(morton_encode(v << 1 * CHAR_BIT) == morton_expand(v) << 1);
    assert(morton_encode(v << 2 * CHAR_BIT) == morton_expand(v) << 2);
  }

#if 0
  typedef unsigned un;

  assert(000000000000000000000000_b == encode((un)000000000000000000000000_b));
  assert(000000000000001001001001_b == encode((un)000000000000000000001111_b));
  assert(001001001001000000000000_b == encode((un)000000000000000011110000_b));
  assert(001001001001001001001001_b == encode((un)000000000000000011111111_b));

  assert(000000000000010010010010_b == encode((un)000000000000111100000000_b));
  assert(000000000000011011011011_b == encode((un)000000000000111100001111_b));
  assert(001001001001010010010010_b == encode((un)000000000000111111110000_b));
  assert(001001001001011011011011_b == encode((un)000000000000111111111111_b));

  assert(010010010010010010010010_b == encode((un)000000001111111100000000_b));
  assert(011011011011011011011011_b == encode((un)000000001111111111111111_b));

  assert(100100100100100100100100_b == encode((un)111111110000000000000000_b));
  assert(101101101101101101101101_b == encode((un)111111110000000011111111_b));
  assert(110110110110110110110110_b == encode((un)111111111111111100000000_b));

  assert(111111111111111111111111_b == encode((un)111111111111111111111111_b));
#endif

  assert(0x249249 == _part3(0xff));

  for (unsigned v = 0; v < 256; ++v) {
    assert(_p30[v] == morton_expand(v));
    assert(v == morton_shrink(_p30[v]));
  }

  for (unsigned v = 0; v < 0x1000000; ++v) {
    assert(v == morton_decode(morton_encode(v)));
  }

  return EXIT_SUCCESS;
}
