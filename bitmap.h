#pragma once
#include <stdint.h>

typedef struct {
  char *buffer; 
  int size;
  int bits;
} BitMap;

//crea una nuova bitmap con un buffer costituito da un array di char
void BitMap_new(BitMap *bitmap, int bits, char* buffer);

//imposta il bit n-esimo della bitmap al valore 0 o 1
void BitMap_set(BitMap *bitmap, int n, int value);
