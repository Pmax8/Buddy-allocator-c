#pragma once
#include <stdint.h>

typedef struct {
  char *buffer; 
  int size;
  int bits;
} BitMap;

//crea una nuova bitmap con un buffer costituito da un array di char
void BitMap_new(BitMap *bitmap, int bits, char* buffer);
