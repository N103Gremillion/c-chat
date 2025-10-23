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
    
    // update
    update_gui(gui);
    // render
    render_gui(gui);

    EndDrawing();
  }
  
  CloseWindow();
}

void update_gui(GUI* gui) {
  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    handle_left_click(gui);
  }
}

void handle_left_click(GUI* gui) {
  check_handle_toolbar_button_click(gui->toolbar);
}

void render_gui(GUI* gui) {
  ClearBackground(gui->background_color);
  render_toolbar(gui->toolbar);
}

void load_set_textures(GUI **gui) {
  load_set_toolbar_textures(&((*gui)->toolbar));
}

void free_gui(GUI* gui) {
  free_toolbar(gui->toolbar);
  free(gui);
}