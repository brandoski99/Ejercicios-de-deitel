#include <stdio.h>

int main() {
  int row = 0, columns = 0;
  int size = 5;

row_loop:
  if (row >= size)
    goto end_row;

col_loop:
  if (columns >= size)
    goto end_col;

  if (row == 0 || row == size - 1 || columns == 0 || columns == size - 1) {
    printf("*");
  } else {
    printf(" ");
  }
  columns++;
  goto col_loop;
end_col:
  columns = 0;
  row++;
  printf("\n");
  goto row_loop;

end_row:
  return 0;
}
