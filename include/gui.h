#ifndef MESSAGING_GUI_H
#define MESSAGING_GUI_H

#include <stdlib.h>

#include "utils.h"
#include "toolbar.h"
#include "gui_config.h"

#include "raylib.h"
#include "raygui.h"

#define RAYGUI_IMPLEMENTATION

typedef struct GUI {
  int height;
  int width;
  int fps;
  Color background_color;
  Toolbar *toolbar;
} GUI;

GUI* init_gui();
void setup_messaging_window(GUI* gui);

#endif
