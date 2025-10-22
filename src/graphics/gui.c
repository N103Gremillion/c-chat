#include "gui.h"

GUI* init_gui() {
  GUI *gui = MALLOC(GUI, 1);

  gui->height = GUI_WINDOW_HEIGHT;
  gui->width = GUI_WINDOW_WIDTH;
  gui->fps = FPS;
  gui->background_color = GUI_BACKGROUND_COLOR;
  gui->toolbar = init_toolbar();
  return gui;
}

void setup_messaging_window(GUI* gui) {
  // SetConfigFlags(FLAG_WINDOW_UNDECORATED); // don't show the default header (I am making my own)
  InitWindow(gui->width, gui->height, "");
  SetWindowState(FLAG_WINDOW_UNDECORATED);

  load_set_textures(&gui);
  SetTargetFPS(gui->fps);

  while (!WindowShouldClose()) {
    BeginDrawing();

    // draw background
    ClearBackground(gui->background_color);
    render_toolbar(gui->toolbar);

    EndDrawing();
  }
  
  CloseWindow();
}

void load_set_textures(GUI **gui) {
  load_set_toolbar_textures(&((*gui)->toolbar));
}