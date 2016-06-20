/* github.com/rubicks/libmorton/binlit.h */

#include "limits.h"
#include "stdint.h"

/* http://embeddedgurus.com/barr-code/2009/09/binary-literals-in-c/ */

/* internal macros */
#define _HEX(n) 0x##n##LU
#define _B8(x)                                                     \
  (((x & 0x0000000FLU) ? 1 : 0) | ((x & 0x000000F0LU) ? 2 : 0) |   \
   ((x & 0x00000F00LU) ? 4 : 0) | ((x & 0x0000F000LU) ? 8 : 0) |   \
   ((x & 0x000F0000LU) ? 16 : 0) | ((x & 0x00F00000LU) ? 32 : 0) | \
   ((x & 0x0F000000LU) ? 64 : 0) | ((x & 0xF0000000LU) ? 128 : 0))

/* user-visible macros */
#define B8(d) ((uint8_t)_B8(_HEX(d)))
#define B16(byte1, byte0) ((uint16_t)(B8(byte1) << 8) | (uint16_t)(B8(byte0)))
#define B32(byte3, byte2, byte1, byte0) \
  ((uint32_t)(B16(byte3, byte2) << 16) | (uint32_t)(B16(byte1, byte0)))
