/* github.com/rubicks/libmorton/util.c */

#include "util.h"

#include "binlit.h"

#if HAVE_CONFIG_H
#include "config.h"
#else
#error "missing config.h"
#endif

/* returns the largest power of two that does not exceed the given number */
uint32_t
util_floor2(uint32_t v)
{
  uint32_t ret;
  do {
    ret = v;
  } while (v &= v - 1);
  return ret;
}

uint32_t
util_cardinality(uint32_t v)
{
  uint32_t c = 0;
  for (; v; ++c) {
    v &= v - 1;
  }
  return c;
}

uint32_t
util_part3(uint32_t v)
{
  v &= 0xffffff;
  v = (v | (v << 16)) & (uint32_t)0x0000ff;
  v = (v | (v << 8)) & (uint32_t)0x00f00f;
  v = (v | (v << 4)) & (uint32_t)0x0c30c3;
  v = (v | (v << 2)) & (uint32_t)0x249249;
  return v;
}
