#include "LatticePaths.h"

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
  {
    grid[i] = (unsigned long *) calloc(gridSize, sizeof(unsigned long));
  }

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
