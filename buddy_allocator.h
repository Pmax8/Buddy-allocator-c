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

//individua il livello al quale dovrebbe trovarsi un blocco di size data
int Find_level(BuddyAllocator* a, int size);

//imposta ricorsivamente i figli del bit dato, al valore di 0 o 1 
void Set_children(BuddyAllocator* a, int bit, int value);

//imposta ricorsivamente il genitore del bit dato, al valore di 0 o 1
void Set_parent(BuddyAllocator* a, int bit, int value);
