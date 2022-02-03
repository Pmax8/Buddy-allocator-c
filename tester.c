#include "buddy_allocator.h"
#include "bitmap.h"
#include <stdio.h>

#define BITMAP_SIZE 8
#define BLOCK_SIZE 8
#define MEM_SIZE 128

char buffer[BITMAP_SIZE];
char memory[MEM_SIZE];
BuddyAllocator ba;

int main(int argc, char** argv) {
  printf("\n---TEST ALLOCAZIONE MEMORIA---\n\n");
  BuddyAllocator_new(&ba, memory, MEM_SIZE, BLOCK_SIZE, buffer, BITMAP_SIZE);
  printf("--TEST 1:Alloc e free--\n\n");
  printf("-ALLOCAZIONE MEMORIA-\n\n");
  void* block_1=BuddyAllocator_alloc(&ba, 3);
  printf("-FREE-\n\n");
  BuddyAllocator_free(&ba, block_1);
  printf("--TEST ALLOCAZIONE IN SERIE:--\n\n");
  printf("-ALLOCAZIONE PRIMO BLOCCO-\n\n");
  block_1=BuddyAllocator_alloc(&ba, 50);
  printf("-ALLOCAZIONE SECONDO BLOCCO-\n\n");
  void* block_2=BuddyAllocator_alloc(&ba, 10);
  printf("-ERRORE DI ALLOCAZIONE-\n\n");
  void* block_3=BuddyAllocator_alloc(&ba, 40);
  printf("--TEST PER LA FUNZIONE CHE LIBERA MEMORIA:--\n\n");
  printf("-LIBERIAMO IL BLOCCO 3 NON ALLOCATO-\n\n");
  BuddyAllocator_free(&ba, block_3);
  printf("-FREE SECONDO BLOCCO-\n\n");
  BuddyAllocator_free(&ba, block_2);
  printf("-FREE PRIMO BLOCCO-\n\n");
  BuddyAllocator_free(&ba, block_1); 
  printf("-LIBERIAMO IL PRIMO BLOCCO PRECEDENTEMENTE LIBERATO-\n\n");
  BuddyAllocator_free(&ba, block_1); 
  printf("\n\n---TEST TERMINATO---\n\n");
  return 0; 
}

  
