#include "bitmap.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void BitMap_new(BitMap* bitmap, int bits, char* buffer){
   bitmap->buffer = buffer;
   bitmap->bits = bits;
   //calcolo la dimensione in byte
   if (bits % 8 == 0) {
      bitmap->size = bits/8; }
   else {
      bitmap->size = bits/8 + 1;
      }
}

void BitMap_set(BitMap* bitmap, int n, int value) {
    int byte = n / 8;
    assert(byte < bitmap->size);
    if (value) {
    bitmap->buffer[byte] |= 1 << (n & 7);
}   else {
    bitmap->buffer[byte] &= ~(1 << (n & 7));
}
}

 int BitMap_get(BitMap* bitmap, int n) {
    int byte = n / 8;
    assert(byte < bitmap->size);
    return bitmap->buffer[byte] & (1 << (n & 7)) ? 1 : 0;
}
