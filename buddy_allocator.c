#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "buddy_allocator.h"

void BuddyAllocator_new(BuddyAllocator* a, char* memory,  int max_size,  int block_size, char* bitmap_buffer,  int bitmap_size){
  a->memory = memory;
  a->max_size  = max_size;
  a->block_size = block_size;
  //calcolo il numero di livelli totali necessari 
  a->levels = log2(max_size / block_size);
  //calcolo il numero di bit necessari per rappresentare tutti i livelli, livello 0 incluso, e controllo che la bitmap sia abbastanza grande
  int bits = pow(2, a->levels+1)-1;
  assert(bitmap_size>=(bits/8+1));
  BitMap_new(&a->bitmap, bits, bitmap_buffer);
  printf("Nuovo Buddy Allocator creato:\nMemory size: %d\nMinimum block size: %d\nBitmap size: %d\n\n", max_size, block_size, bitmap_size);
}
 
