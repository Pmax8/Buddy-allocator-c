# Buddy memory allocator in C

An implementation of the **buddy allocation** algorithm in C, where the state of the memory is tracked with a **bitmap** that represents a complete binary tree.
Built as a pair project for the Operating Systems course at Sapienza University of Rome.

## How it works

- The managed memory is split recursively in halves: the root of the tree is the whole memory, every level below holds blocks half the size of the level above, down to the minimum block size.
- Each node of the tree is one bit of the bitmap: `1` means the block (or part of it) is in use, `0` means it is free.
- **Allocation** finds the smallest level whose blocks fit the requested size, takes the first free block on that level, and marks it as used together with all its ancestors and descendants.
- The allocator stores the block's bitmap index in a small header in front of the returned pointer, so `free` does not need the size.
- **Free** marks the block and its descendants as free, then walks up the tree merging the block with its *buddy* whenever both are free.
- Error cases are handled: out of memory, `NULL` pointer, double free.
- `BitMap_print` prints the bitmap as a tree after each operation, to follow what the allocator is doing.

## Project structure

| File | Content |
|---|---|
| `bitmap.c` / `bitmap.h` | Bitmap data structure: create, set, get and print bits |
| `buddy_allocator.c` / `buddy_allocator.h` | Allocator: initialisation, `alloc`, `free`, recursive marking of parents and children |
| `tester.c` | Test program: single allocation, sequential allocations, out-of-memory, freeing a non-allocated block, double free |
| `Makefile` | Builds the static library `lib.a` and the `tester` executable |
| `report-progetto.pdf` | Project report (in Italian) |

## Build and run

Requirements: `gcc` and `make` (Linux, macOS or WSL).

```bash
make
./tester
```

`make clean` removes the build files.

## API

```c
void  BuddyAllocator_new(BuddyAllocator* a, char* memory, int max_size,
                         int block_size, char* bitmap_buffer, int bitmap_size);
void* BuddyAllocator_alloc(BuddyAllocator* a, int size);
void  BuddyAllocator_free(BuddyAllocator* a, void* ptr);
```

## Known limitations

- The managed memory is a fixed buffer provided by the caller; the allocator does not request memory from the operating system (`mmap`).
- Each allocation reserves 4 bytes for the index header, which matters for very small blocks.
- Debug messages are printed on every operation; a production version would make them optional.
