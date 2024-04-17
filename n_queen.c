#include <stdio.h>
#include <time.h>

int is_safe(int row, int col, int board[10][10], int N) {
  int k, l;
  for (k = row - 1; k >= 0; k--) {
    if (board[k][col] == 1)
      return 0;
  }

  k = row - 1;
  l = col - 1;
  while (k >= 0 && l >= 0) {
    if (board[k][l] == 1)
      return 0;
    k--;
    l--;
  }

  k = row - 1;
  l = col + 1;
  while (k >= 0 && l <= N) {
    if (board[k][l] == 1)
      return 0;
    k--;
    l++;
  }
  return 1;
}

int n_queen(int row, int n, int N, int board[10][10]) {
  int j;
  if (n == 0)
    return 1;

  for (j = 0; j < N; j++) {
    if (is_safe(row, j, board, N)) {
      board[row][j] = 1;

      if (n_queen(row + 1, n - 1, N, board))
        return 1;

      board[row][j] = 0;
    }
  }
  return 0;
}

int main() {
  clock_t start = clock();
  int board[10][10];
  int size = 4;

  printf("\nEnter the number of rows & columns: ");
  scanf("%d", &size);

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      board[i][j] = 0;
    }
  }

  int res = n_queen(0, size, size, board);

  if (res == 0) {
    printf("Solution does not exist\n");
    return 1;
  } else
    printf("Solution exists\n");

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%d\t", board[i][j]);
    }
    printf("\n");
  }

  clock_t end = clock();
  double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
  printf("Time Taken for execution => %f secs\n", time_taken);

  return 0;
}
