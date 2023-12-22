/*
 * 在找到最大公因数的时候出现了问题，采用了辗转相除法
 */

#include <stdio.h>

typedef struct Score {
  int symbol;
  long z_s, f_z, f_m;
} Score;

void init(Score *a) {
  if (a->f_z < 0) {
    a->symbol = -1;
    a->f_z = -a->f_z;
  } else {
    a->symbol = 1;
  }
}

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  if (a <= b) {
    gcd(b, a);
  } else {
    gcd(b, a % b);
  }
}

Score to_simple(Score a) {
  Score c = {0};
  int l;
  if (a.f_z != 0) {
    c.z_s = a.f_z / a.f_m;
    c.f_z = a.f_z % a.f_m;
    c.f_m = a.f_m;
    c.symbol = a.symbol;
    l = gcd(c.f_z, c.f_m);
    c.f_z /= l;
    c.f_m /= l;
  } else {
    c = a;
  }
  return c;
}

Score add(Score a, Score b) {
  Score c = {0};
  c.f_m = a.f_m * b.f_m;
  c.f_z = a.symbol * a.f_z * b.f_m + a.f_m * b.symbol * b.f_z;
  if (c.f_z < 0) {
    c.symbol = -1;
    c.f_z = -c.f_z;
  } else {
    c.symbol = 1;
  }
  return c;
}

Score sub(Score a, Score b) {
  Score c = {0};
  c.f_m = a.f_m * b.f_m;
  c.f_z = a.symbol * a.f_z * b.f_m - a.f_m * b.symbol * b.f_z;
  if (c.f_z < 0) {
    c.symbol = -1;
    c.f_z = -c.f_z;
  } else {
    c.symbol = 1;
  }
  return c;
}

Score mul(Score a, Score b) {
  Score c = {0};
  c.f_m = a.f_m * b.f_m;
  c.f_z = a.symbol * a.f_z * b.symbol * b.f_z;
  if (c.f_z < 0) {
    c.symbol = -1;
    c.f_z = -c.f_z;
  } else {
    c.symbol = 1;
  }
  return c;
}

Score div(Score a, Score b) {
  Score c = {0};
  if (b.f_z == 0) {
    c.symbol = 0;
  } else {
    c.f_m = a.f_m * b.f_z;
    c.f_z = a.symbol * a.f_z * b.symbol * b.f_m;
    if (c.f_z < 0) {
      c.symbol = -1;
      c.f_z = -c.f_z;
    } else {
      c.symbol = 1;
    }
  }
  return c;
}

void output(Score a) {
  if (a.symbol == 0) {
    printf("Inf");
  } else {
    if (a.symbol == -1) {
      printf("(");
    }
    if (a.z_s != 0 && a.f_z != 0) {
      printf("%ld %ld/%ld", a.symbol * a.z_s, a.f_z, a.f_m);
    } else if (a.z_s != 0) {
      printf("%ld", a.symbol * a.z_s);
    } else if (a.f_z != 0) {
      printf("%ld/%ld", a.symbol * a.f_z, a.f_m);
    } else {
      printf("0");
    }
    if (a.symbol == -1) {
      printf(")");
    }
  }
}

int main() {
  Score a = {0}, b = {0};
  scanf("%ld/%ld %ld/%ld", &a.f_z, &a.f_m, &b.f_z, &b.f_m);
  init(&a), init(&b);
  output(to_simple(a)), printf(" + "), output(to_simple(b)), printf(" = "),
      output(to_simple(add(a, b))), printf("\n");
  output(to_simple(a)), printf(" - "), output(to_simple(b)), printf(" = "),
      output(to_simple(sub(a, b))), printf("\n");
  output(to_simple(a)), printf(" * "), output(to_simple(b)), printf(" = "),
      output(to_simple(mul(a, b))), printf("\n");
  output(to_simple(a)), printf(" / "), output(to_simple(b)), printf(" = "),
      output(to_simple(div(a, b))), printf("\n");
}
