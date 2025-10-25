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
  enum Page page;
} GUI;

GUI* init_gui();
void setup_messaging_window(GUI* gui);
void update_gui(GUI* gui);
void render_current_page(GUI* gui);
void render_gui(GUI* gui);
void handle_left_click(GUI* gui);
void load_set_textures(GUI** gui);
void free_gui(GUI* gui);

#endif
