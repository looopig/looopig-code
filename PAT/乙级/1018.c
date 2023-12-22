#include <stdio.h>

typedef struct User {
  int sheng, ping, fu;
  int C, J, B;
} User;

void print(User user) {
  if (user.B >= user.C && user.B >= user.J) {
    printf("%c", 'B');
  } else if (user.C >= user.B && user.C >= user.J) {
    printf("%c", 'C');
  } else if (user.J >= user.C && user.J >= user.B) {
    printf("%c", 'J');
  }
}

int main() {
  User jia = {0}, yi = {0};
  int N;
  char c_jia, c_yi;
  scanf("%d%c", &N, &c_yi);
  for (int count = 0; count < N; count++) {
    scanf("\n%c %c", &c_jia, &c_yi);
    if (c_jia == c_yi) {
      jia.ping++, yi.ping++;
    } else {
      switch (c_jia) {
      case 'C':
        if (c_yi == 'J') {
          jia.sheng++, yi.fu++;
          jia.C++;
        } else if (c_yi == 'B') {
          jia.fu++, yi.sheng++;
          yi.B++;
        }
        break;
      case 'J':
        if (c_yi == 'C') {
          jia.fu++, yi.sheng++;
          yi.C++;
        } else if (c_yi == 'B') {
          jia.sheng++, yi.fu++;
          jia.J++;
        }
        break;
      case 'B':
        if (c_yi == 'C') {
          jia.sheng++, yi.fu++;
          jia.B++;
        } else if (c_yi == 'J') {
          jia.fu++, yi.sheng++;
          yi.J++;
        }
      }
    }
  }
  printf("%d %d %d\n", jia.sheng, jia.ping, jia.fu);
  printf("%d %d %d\n", yi.sheng, yi.ping, yi.fu);
  print(jia), printf(" "), print(yi);
}
