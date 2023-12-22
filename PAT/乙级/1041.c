#include <stdio.h>

typedef struct Student {
  long student_num;
  int kaoshi;
} Student;

int main() {
  int N, M;
  long student_num;
  int shiji, kaoshi;
  scanf("%d", &N);
  Student students[N + 1];
  for (int count = 0; count < N; count++) {
    scanf("%ld %d %d", &student_num, &shiji, &kaoshi);
    students[shiji].student_num = student_num;
    students[shiji].kaoshi = kaoshi;
  }
  scanf("%d", &M);
  for (int count = 0; count < M; count++) {
    scanf("%d", &shiji);
    printf("%ld %d\n", students[shiji].student_num, students[shiji].kaoshi);
  }
}
