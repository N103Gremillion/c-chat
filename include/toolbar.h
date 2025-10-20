#ifndef TOOLBAR_H
#define TOOLBAR_H

#include "gui_config.h"
#include "utils.h"

#include "raylib.h"
#include "raygui.h"

// exit button
#define EXIT_BUTTON_HEIGHT 100
#define EXIT_BUTTON_WIDTH 100
#define EXIT_BUTTON_X 900
#define EXIT_BUTTON_Y 0
#define EXIT_BUTTON_COLOR (Color) {237, 19, 19, 255}

// toolbar
#define TOOLBAR_HEIGHT 100
#define TOOLBAR_WIDTH GUI_WINDOW_WIDTH
#define TOOLBAR_X 0
#define TOOLBAR_Y 0
#define TOOLBAR_COLOR (Color) {47, 90, 158, 255} 

typedef struct ExitButton {
  int x;
  int y;
  int width;
  int height;
  Color color;
} ExitButton;

typedef struct Toolbar {
  Rectangle bounds;
  int x;
  int y;
  int width;
  int height;
  Color color;
  ExitButton *exit_button;
} Toolbar;

Toolbar* init_toolbar();
ExitButton* init_exit_button();
void render_toolbar(Toolbar* toolbar);

#endif