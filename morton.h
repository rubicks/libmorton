/* github.com/rubicks/libmorton/morton.h */

#ifndef MORTON_H
#define MORTON_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

uint32_t morton_expand(uint32_t);
uint32_t morton_shrink(uint32_t);
uint32_t morton_encode(uint32_t);
uint32_t morton_decode(uint32_t);

#ifdef __cplusplus
}
#endif

#endif  // ndef MORTON_H
