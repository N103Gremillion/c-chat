#ifndef TOOLBAR_H
#define TOOLBAR_H

#include "gui_config.h"
#include "utils.h"

#define TOOLBAR_HEIGHT 100

typdef struct Toolbar {
  int width;
  int height;
} Toolbar;

Toolbar* init_toolbar();

#endif