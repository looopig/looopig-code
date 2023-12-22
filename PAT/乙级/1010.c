/*
 * 我的解题思路中读取输入的值是采用读取最后一个字符是回车则退出读取循环
 * 而在此读取最后一个字符需要注意一些细节，就是 scanf("%d %d%c") 第二个 %d 与 %c
 * 之间不能有空格，若是存在空格，则会默认跳过一个空格读取字符，则就回造成数据被读成字符
 * 导致不能退出读取循环，而 PAT 中使用 debug
 * 案例回超时，但是同样能通过全部测试点
 */

#include <stdio.h>

int main() {
  int pol[1005] = {0}, coe, ind;
  char c;
  do {
    scanf("%d %d%c", &coe, &ind, &c);
    if (ind != 0) {
      pol[ind - 1] += ind * coe;
    }
  } while (c != '\n');
  for (int count = 1004; count >= 0; count--) {
    if (pol[count] != 0) {
      if (c == '\n') {
        printf("%d %d", pol[count], count);
        c = ' ';
      } else {
        printf(" %d %d", pol[count], count);
      }
    }
  }
  if (c != ' ') {
    printf("%d %d", 0, 0);
  }
}
