#include "toolbar.h"

Toolbar* init_toolbar() {
  Toolbar *toolbar = MALLOC(Toolbar, 1);

  toolbar->bounds = (Rectangle) {
    .x = TOOLBAR_X, 
    .y = TOOLBAR_Y, 
    .width = TOOLBAR_WIDTH, 
    .height = TOOLBAR_HEIGHT
  };
  toolbar->color = TOOLBAR_COLOR;

  // buttons
  toolbar->buttons = init_toolbar_buttons();
  return toolbar;
}

Button** init_toolbar_buttons() {
  Button **buttons = MALLOC(Button*, TOOLBAR_BUTTON_COUNT);

  for(int i=0; i<TOOLBAR_BUTTON_COUNT; i++) {
    buttons[i] = MALLOC(Button, 1);
  }

  // exit button
  buttons[0]->bounds = (Rectangle) {
    .x = EXIT_BUTTON_X, 
    .y = EXIT_BUTTON_Y, 
    .width = EXIT_BUTTON_WIDTH, 
    .height = EXIT_BUTTON_HEIGHT
  };
  buttons[0]->color = EXIT_BUTTON_COLOR;
  buttons[0]->type = EXIT;

  return buttons;
}

void load_set_toolbar_textures(Toolbar **toolbar) {
  // load the button textures
  for (int i=0; i<TOOLBAR_BUTTON_COUNT; i++){
    Button *button = (*toolbar)->buttons[i];
    if (!button) continue;

    if (button->type == EXIT) {
      button->texture = LoadTexture(EXIT_BUTTON_IMG_PATH);
      button->hover_texture = LoadTexture(EXIT_BUTTON_HOVER_IMG_PATH);
    } 
  }
}

void render_toolbar(Toolbar* toolbar) {

  // draw toolbar
  DrawRectangleRec(toolbar->bounds, toolbar->color);
  
  // render buttons
  Vector2 mouse_pos = GetMousePosition();

  for (int i = 0; i<TOOLBAR_BUTTON_COUNT; i++) {
    Button* button = toolbar->buttons[i];
    if (!button) continue;
    
    bool is_hovering = CheckCollisionPointRec(mouse_pos, button->bounds);
    if (button->type == EXIT) {
      if (is_hovering) {
        DrawTexture(button->hover_texture, button->bounds.x, button->bounds.y, WHITE);
      } 
      else {
        DrawTexture(button->texture, button->bounds.x, button->bounds.y, WHITE);
      }
    }
  }
}

void check_handle_toolbar_button_click(Toolbar* toolbar) {
  Vector2 mouse_pos = GetMousePosition();

  for (int i=0; i < TOOLBAR_BUTTON_COUNT; i++) {
    Button* button = toolbar->buttons[i];
    if (!button) continue;

    bool is_hovering = CheckCollisionPointRec(mouse_pos, button->bounds);

    if (button->type == EXIT) {
      if (is_hovering) {
        CloseWindow();
      }
    }
  }
}

void free_toolbar(Toolbar* toolbar) {
  // free all the buttons first
  for (int i=0; i<TOOLBAR_BUTTON_COUNT; i++) {
    free(toolbar->buttons[i]);
  }
  free(toolbar->buttons);
  free(toolbar);
}


