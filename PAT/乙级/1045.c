/*
 * 快速排序的每一个主元都会被放在最终位置上，所以只需要对其排一次序，
 * 就可以知道其可能是主元，因为可能左右刚好有相同的数对换了位置（第一次
 * 我就犯了这个错误），所以除了对比是否在同一个位置还要检查左边最大的值要小于
 * 主元，右边最小的值大于主元，由于主元位置不变，所以只需要检查一边就可以，
 * 这是因为排序之后左右两边的个数可以确定，若是右边的最大值小于主元，则可以得到
 * 大于主元的数全在右边了，所以就可以确定
 */
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main() {
  int list[100005], list_1[100005], list_2[100005];
  int N, num = 0, temp = -1;
  scanf("%d", &N);
  for (int count = 0; count < N; count++) {
    scanf("%d", &list_1[count]);
    list_2[count] = list_1[count];
  }
  qsort(list_2, N, sizeof(int), cmp);
  for (int count = 0; count < N; count++) {
    if (list_1[count] == list_2[count] && list_1[count] > temp) {
      list[num++] = list_1[count];
    }
    if (temp < list_1[count]) {
      temp = list_1[count];
    }
  }
  printf("%d\n", num);
  if (num == 0) {
    printf("\n");
  } else {
    for (int count = 0; count < num; count++) {
      if (count == 0) {
        printf("%d", list[count]);
      } else {
        printf(" %d", list[count]);
      }
    }
  }
}
