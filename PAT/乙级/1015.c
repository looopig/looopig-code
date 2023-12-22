/*
 * 第一类：德分与才分都达到了优先录取线
 * 第二类：才分不到但是德分导优先录取线
 * 第三类：德才均低于优先录取线，但是德分不低于才分
 * 第四类：其他
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
  int id, tag;
  int de, cai, sum;
} Student;

int cmp(const void *a, const void *b) {
  Student studen1 = *(Student *)a;
  Student studen2 = *(Student *)b;
  if (studen1.tag != studen2.tag) {
    return studen1.tag - studen2.tag;
  } else if (studen1.sum != studen2.sum) {
    return studen2.sum - studen1.sum;
  } else if (studen1.de != studen2.de) {
    return studen2.de - studen1.de;
  } else {
    return studen1.id - studen2.id;
  }
}

int main() {
  int N, L, H, M, lower_num = 0;
  int id, de, cai;
  scanf("%d %d %d", &N, &L, &H);
  Student students[N];
  for (int count = 0; count < N; count++) {
    scanf("%d %d %d", &id, &de, &cai);
    if (de >= L && cai >= L) {
      if (de >= H && cai >= H) {
        students[count].tag = 1;
      } else if (de >= H && cai < H) {
        students[count].tag = 2;
      } else if (de < H && cai < H && de > cai) {
        students[count].tag = 3;
      } else {
        students[count].tag = 4;
      }
      students[count].id = id;
      students[count].de = de;
      students[count].cai = cai;
      students[count].sum = de + cai;
    } else {
      students[count].tag = 5;
      lower_num++;
    }
  }
  M = N - lower_num;
  printf("%d\n", M);
  qsort(students, N, sizeof(Student), cmp);
  for (int count = 0; count < M; count++) {
    printf("%d %d %d\n", students[count].id, students[count].de,
           students[count].cai);
  }
}
