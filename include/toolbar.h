#ifndef TOOLBAR_H
#define TOOLBAR_H

#include "gui_config.h"
#include "utils.h"

#include "raylib.h"
#include "raygui.h"

// exit button
#define EXIT_BUTTON_HEIGHT 50
#define EXIT_BUTTON_WIDTH 50
#define EXIT_BUTTON_X 925
#define EXIT_BUTTON_Y 25
#define EXIT_BUTTON_COLOR (Color) {237, 19, 19, 255}
#define EXIT_BUTTON_IMG_PATH "textures/toolbar/exit_button.png"
#define EXIT_BUTTON_HOVER_IMG_PATH "textures/toolbar/exit_button_hover.png"

// toolbar
#define TOOLBAR_HEIGHT 100
#define TOOLBAR_WIDTH GUI_WINDOW_WIDTH
#define TOOLBAR_X 0
#define TOOLBAR_Y 0
#define TOOLBAR_COLOR (Color) {55, 64, 85, 255} 
#define TOOLBAR_BUTTON_COUNT 1

enum ButtonType {
  EXIT
};

typedef struct Button {
  Rectangle bounds;
  Color color;
  enum ButtonType type;
  Texture2D texture;
  Texture2D hover_texture;
} Button;

typedef struct Toolbar {
  Rectangle bounds;
  float ratio;
  Color color;
  Button **buttons;
} Toolbar;

Toolbar* init_toolbar();
Button** init_toolbar_buttons();
void load_set_toolbar_textures(Toolbar** toolbar);
void render_toolbar(Toolbar* toolbar);

#endif