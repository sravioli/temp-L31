#include <ctype.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  char name[4];
  int score;
} Entry;

int main() {
  Entry entries[] = {
      {"Ali", 123},
      {"Bob", 456},
      {"Cha", 789},
  };
  int num_entries = sizeof(entries) / sizeof(Entry);

  printf("%6s  %-3s  %-6s\n", "RANK", "NAME", "SCORE");
  int i = 0;
  while (i < num_entries) {
    entries[i].name[3] = '\0';

    int j = 0;
    while (j < 3) {
      entries[i].name[j] = toupper(entries[i].name[j]);
      j = j + 1;
    }
    printf("%6d  %-4s  %-6d\n", i + 1, entries[i].name, entries[i].score);
    i = i + 1;
  }

  return 0;
}
