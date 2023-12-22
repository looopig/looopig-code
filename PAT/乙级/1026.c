#include <stdio.h>

int main() {
  int c1, c2, time_, hh, mm, ss;
  scanf("%d %d", &c1, &c2);
  time_ = ((c2 - c1) / 100.0 + 0.5);
  ss = time_ % 60;
  time_ /= 60;
  mm = time_ % 60;
  hh = time_ / 60;
  printf("%02d:%02d:%02d", hh, mm, ss);
}
