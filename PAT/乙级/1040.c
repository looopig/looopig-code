/*
 * 思路：
 * P 记录个数，A 看 P 的个数，T 看 A 的个数
 * 每次读取一个字符然后很据是 P A T 分情况讨论
 * 1.若是 P 则在 P 的个数上自增 1
 * 2.若是 A，则观察 P 的个数，加在 A 的个数中，因为若是 P 个数为 n 则证明
 * 在 A 前面由 n 个 P，则这个 A 可以和前面的 n 个 P 组合成 n 个 PA
 * 3. 若是 T 则观察前面有几个 A，再加到 T 的个数中，因为这个 T 前面有 n 个 A
 * 则证明前面有 n 个 PA，则这个 T 可以和 n 个 PA 形成 n 个PAT
 * 最后返回的则是 T 的个数，而由于可能会非常的大，所以采用无符号整形
 * 并且每次观察 T 的个数对 1000000007 取余，因为 PA 的个数最高是 2500000000 不会
 * 大于 uint 的范围，所以可以随时对 list[2] 取余数
 */

#include <stdio.h>

int main() {
  unsigned int list[3] = {0};
  char c;
  c = getchar();
  while (c != '\n') {
    switch (c) {
    case 'P':
      list[0]++;
      break;
    case 'A':
      list[1] += list[0];
      break;
    case 'T':
      list[2] += list[1];
      list[2] %= 1000000007;
    }
    c = getchar();
  }
  printf("%u", list[2]);
}
