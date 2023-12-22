/*
 * 周期是第一与第二串字符串的第一对相同的大写字母在英文字母表的位置 A ~ G
 * 时钟是第一与第二串字符串的第二对相同的字符表示，数字 0 ~ 9 与 A ~ N
 * 分钟是的第三与第四串字符串的相同英文字母的位置，一共有 60 个字母
 */

#include <stdio.h>

int main() {
  char str[4][60],
      week[7][5] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
  int nums[3] = {-1, -1, -1};
  scanf("%s\n%s\n%s\n%s", str[0], str[1], str[2], str[3]);
  for (int count = 0; count < 60; count++) {
    if (str[0][count] == str[1][count]) {
      if (nums[0] == -1) {
        if (str[0][count] >= 'A' && str[0][count] <= 'G') {
          nums[0] = str[0][count] - 'A';
        }
      } else if (nums[1] == -1) {
        if (str[0][count] >= '0' && str[0][count] <= '9') {
          nums[1] = str[0][count] - '0';
        } else if (str[0][count] >= 'A' && str[0][count] <= 'N') {
          nums[1] = str[0][count] - 'A' + 10;
        }
      }
    }
    if (str[2][count] == str[3][count]) {
      if (nums[2] == -1) {
        if ((str[2][count] >= 'A' && str[2][count] <= 'Z') ||
            (str[2][count] >= 'a' && str[2][count] <= 'z')) {
          nums[2] = count;
        }
      }
    }
  }
  printf("%s %02d:%02d", week[nums[0]], nums[1], nums[2]);
}
