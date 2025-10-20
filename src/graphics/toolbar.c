#include "toolbar.h"

ExitButton* init_exit_button() {
  ExitButton *button = MALLOC(ExitButton);

  button->x = EXIT_BUTTON_X;
  button->y = EXIT_BUTTON_Y;
  button->width = EXIT_BUTTON_HEIGHT;
  button->height = EXIT_BUTTON_HEIGHT;
  button->color = EXIT_BUTTON_COLOR;
}

Toolbar* init_toolbar() {
  Toolbar *toolbar = MALLOC(Toolbar);

  toolbar->x = TOOLBAR_X;
  toolbar->y = TOOLBAR_Y;
  toolbar->width = TOOLBAR_WIDTH;
  toolbar->height = TOOLBAR_HEIGHT;
  toolbar->color = TOOLBAR_COLOR;
  // buttons
  toolbar->exit_button = init_exit_button();
  return toolbar;
}

void render_toolbar(Toolbar* toolbar) {
  // draw toolbar
  DrawRectangle(toolbar->x, toolbar->y, toolbar->width, toolbar->height, toolbar->color);

  // exit button
  DrawRectangle(toolbar->exit_button->x, toolbar->exit_button->y, toolbar->exit_button->width, toolbar->exit_button->height, toolbar->exit_button->color);
}


