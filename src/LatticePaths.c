#include "LatticePaths.h"
#include <stdio.h>

void freeNumbers( unsigned long ** , int );
void freeNumbers(unsigned long ** grid, int size)
{
  for (int i = 0; i < size + 1; i++)
    free(grid[i]);
  free(grid);
}

unsigned long ** allocateGrid(int);
unsigned long ** allocateGrid(int size)
{
  unsigned long gridSize = (unsigned long) size + 1;
  unsigned long ** grid = (unsigned long **) calloc(gridSize, sizeof(unsigned long *));

  for (unsigned long i = 0; i < gridSize; i++)
    grid[i] = (unsigned long *) calloc(gridSize, sizeof(unsigned long));

  return grid;
}

unsigned long LatticePaths_for(int size)
{
  unsigned long ** grid = allocateGrid(size + 1);
  for (int x = size; x >= 0; x--)
  {
    for (int y = size; y >= 0; y--) {
      unsigned long result = 1;
      for (int z = y; z < size; z++)
        result += grid[x + 1][z];

      grid[x][y] = result;
    }
  }

  unsigned long result = grid[0][0];
  freeNumbers(grid, size + 1);
  return result;
}

unsigned long LatticePaths_combinatorialFor(int size)
{
  /* Combonatorial rth element in nth: n!/(r! * (n - r)!) */
  /* (size * 2)! / (size! * (size * 2 - size)!) */
  __uint128_t n = 1;
  __uint128_t r = 1;
  __uint128_t llsize = (__uint128_t) size;

  for (__uint128_t x = llsize * 2; x > llsize; x--)
    n *= x;

  for (__uint128_t x = llsize; x > 1; x--)
    r *= x;

  return (unsigned long) (n / r);
}
