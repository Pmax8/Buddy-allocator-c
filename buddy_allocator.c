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
 
  int Find_level(BuddyAllocator* a, int size){
     assert(size < a->max_size);
     //se il blocco è più piccolo della dimensione minima, si troverà nell'ultimo livello
     if (size <= a->block_size) return a->levels;
     else {
        int lvl= 0;
        int comp = a->max_size / 2;
      	while (size <= comp){
		      lvl++;
		      comp = comp / 2;
        }
   	return lvl;
    }
}

void Set_children(BuddyAllocator* a, int bit, int value) {
	//si ferma quando arriva alla fine dell'array
	if (bit < (&a->bitmap)->bits) {
		BitMap_set(&a->bitmap, bit, value);
		Set_children(a, bit*2+1, value);
		Set_children(a, bit*2+2, value);
	}
}

void Set_parent(BuddyAllocator* a, int bit, int value) {
	BitMap_set(&a->bitmap, bit, value);
	//si ferma quando arriva alla radice
	if (bit != 0) {
	  //indice genitore == (indice figlio sx - 1)/2 == (indice figlio dx - 2)/2
	  if (bit%2 == 0) bit--;
          bit = (bit-1)/2;
	  Set_parent(a, bit, value);
	}
}

