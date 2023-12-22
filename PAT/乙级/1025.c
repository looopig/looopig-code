#include <stdio.h>

typedef struct Link {
  int value, next;
} Link;

int main() {
  int N, K;
  Link link[100001];
  int head_link = 100000, head_link_old, p, pre;
  scanf("%d %d %d", &link[head_link].next, &N, &K);
  for (int count = 0; count < 100000; count++) {
    link[count].next = -1;
  }
  for (int count = 0; count < N; count++) {
    scanf("%d", &p);
    scanf("%d %d", &link[p].value, &link[p].next);
  }
  int num = 0;
  p = link[head_link].next;
  while (p != -1) {
    num++;
    p = link[p].next;
  }
  head_link_old = head_link, pre = link[head_link].next, p = link[pre].next;
  for (int count = 0; count < (int)(num / K); count++) {
    for (int i = 0; i < K - 1; i++) {
      link[pre].next = link[p].next;
      link[p].next = link[head_link_old].next;
      link[head_link_old].next = p;
      p = link[pre].next;
    }
    if (count < (int)(num / K) - 1) {
      head_link_old = pre;
      pre = p, p = link[pre].next;
    }
  }
  p = link[head_link].next;
  while (p != -1) {
    printf("%05d %d ", p, link[p].value);
    if (link[p].next == -1) {
      printf("-1");
    } else {
      printf("%05d\n", link[p].next);
    }
    p = link[p].next;
  }
}
