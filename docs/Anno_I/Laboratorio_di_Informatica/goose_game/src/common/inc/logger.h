#ifndef LOGGER_H
#define LOGGER_H

#include "../inc/term.h"

#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vadefs.h>

struct Logger {
  void (*start)(const char filename[]);
  void (*log)(const char caller[], const char format[], ...);
  void (*stop)();
  void (*disable)();
  void (*enable)();
};

extern struct Logger logger;

#endif  // !LOGGER_H
