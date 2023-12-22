#include <stdio.h>
#include <stdlib.h>

typedef struct List {
  int id, grade;
} List;

int cmp(const void *a, const void *b) {
  List a1 = *(List *)a;
  List a2 = *(List *)b;
  if (a1.grade == a2.grade) {
    return a2.id - a1.id;
  } else {
    return a2.grade - a1.grade;
  }
}

int main() {
  List list[100005] = {0};
  int p, grade, N, max_num = 0;
  scanf("%d", &N);
  for (int count = 0; count < N; count++) {
    scanf("%d %d", &p, &grade);
    list[p].grade += grade;
    list[p].id = p;
    if (max_num < p) {
      max_num = p;
    }
  }
  qsort(list, max_num + 1, sizeof(List), cmp);
  printf("%d %d", list[0].id, list[0].grade);
}
