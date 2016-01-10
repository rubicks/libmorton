/* github.com/rubicks/libmorton/morton.h */

#ifndef MORTON_H
#define MORTON_H

#ifdef __cplusplus
extern "C" {
#endif

unsigned morton_expand(unsigned);
unsigned morton_shrink(unsigned);
unsigned morton_encode(unsigned);
unsigned morton_decode(unsigned);

#ifdef __cplusplus
}
#endif

#endif  // ndef MORTON_H
