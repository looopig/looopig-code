
/*
 * 坑点：测试点 3 存在全部都不合法，只能输出 0
 */
#include <stdio.h>

typedef struct People {
  char name[10];
  int yyyy, mm, dd;
} People;

int compare_max(People people, People people_max) {
  if (people.yyyy > people_max.yyyy ||
      people.yyyy == people_max.yyyy && people.mm > people_max.mm ||
      people.yyyy == people_max.yyyy && people.mm == people_max.mm &&
          people.dd >= people_max.dd) {
    return 1;
  } else {
    return 0;
  }
}

int compare_min(People people, People people_min) {
  if (people.yyyy < people_min.yyyy ||
      people.yyyy == people_min.yyyy && people.mm < people_min.mm ||
      people.yyyy == people_min.yyyy && people.mm == people_min.mm &&
          people.dd <= people_min.dd) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  People people, people_max, people_min;
  People max = {" ", 1814, 9, 6}, min = {" ", 2014, 9, 6};
  people_max = max, people_min = min;
  int N, num = 0;
  scanf("%d", &N);
  for (int count = 0; count < N; count++) {
    scanf("%s %d/%d/%d", people.name, &people.yyyy, &people.mm, &people.dd);
    if (compare_max(people, max) && compare_min(people, min)) {
      num++;
      if (compare_max(people, people_max)) {
        people_max = people;
      }
      if (compare_min(people, people_min)) {
        people_min = people;
      }
    }
  }
  if (num == 0) {
    printf("%d", num);
  } else {
    printf("%d %s %s", num, people_min.name, people_max.name);
  }
}
