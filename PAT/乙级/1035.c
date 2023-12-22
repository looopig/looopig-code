#include <stdio.h>
#include <stdlib.h>
#define max 150

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

void insertsort(int str[max], int n) { qsort(str, n, sizeof(int), cmp); }

void mergesort(int str[max], int n, int N) {
  for (int count = 0; count < N; count += n) {
    qsort(str + count, n < N - count ? n : N - count, sizeof(int), cmp);
  }
}

int is_same(int str_test[max], int str[max], int N) {
  for (int count = 0; count < N; count++) {
    if (str_test[count] != str[count]) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int str_insert[max], insert_p, str_merge[max], merge_p;
  int N, str_real[max], *str;
  scanf("%d", &N);
  for (int count = 0; count < N; count++) {
    scanf("%d", &str_insert[count]);
    str_merge[count] = str_insert[count];
  }
  for (int count = 0; count < N; count++) {
    scanf("%d", &str_real[count]);
  }
  insert_p = merge_p = 2;
  while (insert_p <= N || merge_p <= N) {
    if (insert_p <= N) {
      insertsort(str_insert, insert_p);
      insert_p++;
      if (is_same(str_insert, str_real, N)) {
        printf("Insertion Sort\n");
        insertsort(str_insert, insert_p);
        str = str_insert;
        break;
      }
    }
    if (merge_p <= N) {
      mergesort(str_merge, merge_p, N);
      merge_p *= 2;
      if (is_same(str_merge, str_real, N)) {
        printf("Merge Sort\n");
        mergesort(str_merge, merge_p, N);
        str = str_merge;
        break;
      }
    }
  }
  for (int count = 0; count < N; count++) {
    if (count == 0) {
      printf("%d", str[count]);
    } else {
      printf(" %d", str[count]);
    }
  }
}
