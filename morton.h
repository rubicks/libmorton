/* github.com/rubicks/libmorton/morton.h */

#ifndef MORTON_MORTON_H
#define MORTON_MORTON_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

uint32_t morton_expand(uint32_t);
uint32_t morton_shrink(uint32_t);
uint32_t morton_encode(uint32_t);
uint32_t morton_decode(uint32_t);

#ifdef __cplusplus
}
#endif

#endif  // ndef MORTON_MORTON_H
