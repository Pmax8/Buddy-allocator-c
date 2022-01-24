#include "buddy_allocator.h"
#include "bitmap.h"
#include <stdio.h>

#define BITMAP_SIZE 8
#define BLOCK_SIZE 8
#define MEM_SIZE 128

char buffer[BITMAP_SIZE];
char memory[MEM_SIZE];
BuddyAllocator ba;
