#include <stdio.h>
#include <string.h>

void prefixsuffix(char *pat, int M, int *pps) {
  int length = 0, i = 1;
  pps[0] = 0;
  while (i < M) {
    if (pat[i] == pat[length]) {
      length++;
      pps[i] = length;
      i++;
    } else {
      if (length != 0) {
        length = pps[length - 1];
      } else {
        pps[i] = 0;
        i++;
      }
    }
  }
}

void KMPAlgorithm(char text[], char pattern[]) {
  int i = 0, j = 0;
  int M = strlen(pattern);
  int N = strlen(text);

  int pps[30];
  prefixsuffix(pattern, M, pps);

  while (i < N) {
    if (pattern[j] == text[i]) {
      i++;
      j++;
    }
    if (j == M) {
      printf("Pattern Found at index => %d\n", i - j);
      j = pps[j - 1];
    } else if (i < N && pattern[j] != text[i]) {
      if (j != 0)
        j = pps[j - 1];
      else
        i++;
    }
  }
}

int main() {
  char text[100];
  char pattern[100];
  printf("Enter the text : ");
  scanf("%s", text);
  printf("Enter the pattern : ");
  scanf("%s", pattern);
  printf("\nPattern is found at the following indices \n");
  KMPAlgorithm(text, pattern);
  return 0;
}
