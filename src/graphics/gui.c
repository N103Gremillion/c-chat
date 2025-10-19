#include "gui.h"

GUI* init_gui() {
  GUI *gui = MALLOC(GUI);

  gui->height = GUI_WINDOW_HEIGHT;
  gui->width = GUI_WINDOW_WIDTH;
  gui->fps = FPS;
  gui->background_color = GUI_BACKGROUND_COLOR;

  return gui;
}

void setup_messaging_window(GUI* gui) {
  SetConfigFlags(FLAG_WINDOW_UNDECORATED); // don't show the default header (I am making my own)
  InitWindow(gui->width, gui->height, "");
  SetTargetFPS(gui->fps);

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(gui->background_color);

    EndDrawing();
  }
  
  CloseWindow();
}