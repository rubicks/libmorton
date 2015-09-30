/* github.com/rubicks/mortonlib/morton.h */

#ifndef ___MORTONLIB___MORTON_H___
#define ___MORTONLIB___MORTON_H___

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

#endif  // ndef ___MORTONLIB___MORTON_H___
