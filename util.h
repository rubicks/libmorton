/* github.com/rubicks/libmorton/util.h */

#ifndef MORTON_UTIL_H
#define MORTON_UTIL_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

uint32_t util_floor2(uint32_t);
uint32_t util_cardinality(uint32_t);
uint32_t util_part3(uint32_t);

#ifdef __cplusplus
}
#endif

#endif  // ndef MORTON_UTIL_H
