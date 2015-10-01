/* github.com/rubicks/morton/morton.h */

#ifndef ___MORTON___MORTON_H___
#define ___MORTON___MORTON_H___

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

#endif  // ndef ___MORTON___MORTON_H___
