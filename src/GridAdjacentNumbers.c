#include "GridAdjacentNumbers.h"

typedef long (* elementAccessor) (int * grid [], int row, int column, int element);

long rowAccessor(int * grid [], int row, int column, int element);
long rowAccessor(int * grid [], int row, int column, int element)
{
  return (long) grid[row][column + element];
}

long columnAccessor(int * grid [], int row, int column, int element);
long columnAccessor(int * grid [], int row, int column, int element)
{
  return (long) grid[row + element][column];
}

long upLeftAccessor(int * grid [], int row, int column, int element);
long upLeftAccessor(int * grid [], int row, int column, int element)
{
  return (long) grid[row + element][column + element];
}

long groupProduct(int * grid[], int numberOfElements, int row, int column, elementAccessor);
long groupProduct(int * grid[], int numberOfElements, int row, int column, elementAccessor access)
{
  long product = 1;
  for(int i=0; i < numberOfElements; i++) {
    product *= access(grid, row, column, i);
  }
  return product;
}

long rowProduct(int * grid[], int numberOfElements, int row, int column);
long rowProduct(int * grid[], int numberOfElements, int row, int column)
{
  return groupProduct(grid, numberOfElements, row, column, rowAccessor);
}

long columnProduct(int * grid[], int numberOfElements, int row, int column);
long columnProduct(int * grid[], int numberOfElements, int row, int column)
{
  return groupProduct(grid, numberOfElements, row, column, columnAccessor);
}

long diagonalUpLeft(int * grid[], int numberOfElements, int row, int column);
long diagonalUpLeft(int * grid[], int numberOfElements, int row, int column)
{
  return groupProduct(grid, numberOfElements, row, column, upLeftAccessor);
}

long diagonalUpRight(int * grid[], int numberOfElements, int row, int column);
long diagonalUpRight(int * grid[], int numberOfElements, int row, int column)
{
  long product = 1;
  for(int i=0; i < numberOfElements; i++) {
    product *= (long) grid[row + (numberOfElements - 1) - i][column + i];
  }
  return product;
}

long largestValue(long, long);
long largestValue(long x, long y)
{
  return x > y ? x : y;
}

long GridAdjacentNumbers_largestProduct(int * grid[], int size, int numberOfElements) {
  long largestProduct = 1;
  for(int row=0; row < size; row++) {
    for(int column=0; column < size; column++) {
      bool canFitRow = column + numberOfElements <= size;
      bool canFitColumn = row + numberOfElements <= size;
      if (canFitRow)
        largestProduct = largestValue(largestProduct, rowProduct(grid, numberOfElements, row, column));

      if (canFitColumn)
        largestProduct = largestValue(largestProduct, columnProduct(grid, numberOfElements, row, column));

      if (canFitColumn && canFitRow) {
        largestProduct = largestValue(largestProduct, diagonalUpLeft(grid, numberOfElements, row, column));
        largestProduct = largestValue(largestProduct, diagonalUpRight(grid, numberOfElements, row, column));
      }

    }
  }

  return largestProduct;
}


