/*
 * 遇到两个错误，一个是没有想到市场最大需求量可能要大于总的库存量，还有一个
 * 就是库存与总售价为正数，而不是正正数
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Yuebing {
  float danjia, kucun, zhongshoujia;
} Yuebing;

int cmp(const void *a, const void *b) {
  Yuebing a1 = *(Yuebing *)a;
  Yuebing a2 = *(Yuebing *)b;
  if (a2.danjia > a1.danjia) {
    return 1;
  } else if (a2.danjia < a1.danjia) {
    return -1;
  } else {
    return 0;
  }
}

int main() {
  int N;
  float D;
  scanf("%d %f", &N, &D);
  Yuebing yuebing[N];
  for (int count = 0; count < N; count++) {
    scanf("%f", &yuebing[count].kucun);
  }
  for (int count = 0; count < N; count++) {
    scanf("%f", &yuebing[count].zhongshoujia);
    yuebing[count].danjia = yuebing[count].zhongshoujia / yuebing[count].kucun;
  }
  qsort(yuebing, N, sizeof(Yuebing), cmp);
  float sum = 0;
  int p = 0;
  while (D > 0 && p < N) {
    if (D > yuebing[p].kucun) {
      sum += yuebing[p].zhongshoujia;
      D -= yuebing[p].kucun;
      p++;
    } else {
      sum += (D * yuebing[p].zhongshoujia) / yuebing[p].kucun;
      D = 0;
    }
  }
  printf("%.2f", sum);
}
