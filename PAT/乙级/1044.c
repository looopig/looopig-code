#include <stdio.h>
#include <string.h>

char map_low[13][5] = {"tret", "jan", "feb", "mar", "apr", "may", "jun",
                       "jly",  "aug", "sep", "oct", "nov", "dec"};
char map_high[13][5] = {"",    "tam", "hel", "maa", "huh", "tou", "kes",
                        "hei", "elo", "syy", "lok", "mer", "jou"};

int to_num(char map[13][5], char str[5]) {
  for (int count = 0; count < 13; count++) {
    if (!strcmp(map[count], str)) {
      return count;
    }
  }
  return -1;
}

int main() {
  int high, low, num, N;
  char str_high[5], str_low[5], str[10], c = '\0';
  scanf("%d%c", &N, &c);
  for (int count = 0; count < N; count++) {
    scanf("%[^\n]%c", str, &c);
    if (str[0] <= '9' && str[0] >= '0') {
      sscanf(str, "%d", &num);
      low = num % 13;
      high = num / 13;
      if (low != 0 && high != 0) {
        printf("%s %s\n", map_high[high], map_low[low]);
      } else if (high != 0) {
        printf("%s\n", map_high[high]);
      } else if (low != 0) {
        printf("%s\n", map_low[low]);
      } else if (low == 0 && high == 0) {
        printf("tret\n");
      }
    } else {
      sscanf(str, "%[a-z]%[' ']", str_high, &c);
      if (c == ' ') {
        sscanf(str, "%s %s", str_high, str_low);
        printf("%d\n",
               to_num(map_high, str_high) * 13 + to_num(map_low, str_low));
      } else {
        if (to_num(map_high, str_high) != -1) {
          printf("%d\n", to_num(map_high, str_high) * 13);
        } else {
          printf("%d\n", to_num(map_low, str_high));
        }
      }
    }
  }
}
