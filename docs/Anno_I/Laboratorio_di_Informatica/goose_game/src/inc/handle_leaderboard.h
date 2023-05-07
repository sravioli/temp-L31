#ifndef LEADERBOARD_MODULE_H
#define LEADERBOARD_MODULE_H

#include "../types/entries.h"

/**
 * @brief Sorts entries.
 *
 * This function sorts the Entries array in descending order by score, and then
 * in ascending order by name.
 *
 * @param[in,out] es A pointer to the Entries struct to sort.
 *
 * @return void.
 */
void sort_entries(Entries *es);

/**
 * @brief Appends entries to an existing array.
 *
 * This function appends new entries to an existing Entries array.
 *
 * @param[in,out] existing_entries A pointer to the existing Entries struct to
 * append to.
 * @param[in]     new_entries      A pointer to the Entries struct containing
 * the new entries to append.
 *
 * @return void.
 */
void append_entries(Entries *existing_entries, Entries *new_entries);

#endif  // !LEADERBOARD_MODULE_H
