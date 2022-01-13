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
