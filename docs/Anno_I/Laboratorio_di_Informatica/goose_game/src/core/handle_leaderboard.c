#include "../inc/handle_leaderboard.h"

void swap_entries(Entry *ei, Entry *ej) {
  Entry temp = *ei;
  *ei = *ej;
  *ej = temp;
}

void rm_duplicate_entries(Entries *es) {
  int i = 0;
  int num_entries = get_num_entries(es);
  while (i < num_entries - 1) {
    Entry *curr_entry = get_entry(es, i);
    Entry *next_entry = get_entry(es, i + 1);
    if (strcmp(get_name(curr_entry), get_name(next_entry)) == 0) {
      int j = i + 1;
      while (j < num_entries - 1) {
        set_entry(es, get_entry(es, j + 1), j);
        j = j + 1;
      }
      num_entries = num_entries - 1;
      // Continue checking from this index to ensure no other duplicates were
      // missed
      i = i - 1;
    }
    i = i + 1;
  }
}

void sort_entries(Entries *es) {
  int i = 0;
  while (i < get_num_entries(es)) {
    int j = i + 1;
    while (j < get_num_entries(es)) {
      Entry *ei = get_entry(es, i);
      Entry *ej = get_entry(es, j);
      int is_score_greater = get_final_score(ej) > get_final_score(ei);
      int is_score_equal = get_final_score(ej) == get_final_score(ei);
      int is_name_prev = strcmp(get_name(ej), get_name(ei));
      int should_swap_entries =
          is_score_greater || (is_score_equal && is_name_prev);

      if (should_swap_entries) {
        swap_entries(ei, ej);
      }

      j = j + 1;
    }
    i = i + 1;
  }
  rm_duplicate_entries(es);
}
