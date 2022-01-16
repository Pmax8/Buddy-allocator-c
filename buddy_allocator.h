#pragma once
#include <stdint.h>
#include "bitmap.h"


typedef struct {
  char* memory;
  int levels;
  int max_size;
  int block_size;
  BitMap bitmap;
  } BuddyAllocator;

//crea un nuovo Buddy Allocator
void BuddyAllocator_new(BuddyAllocator* a, char* memory,  int max_size,  int block_size, char* bitmap_buffer,  int bitmap_size);
