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
    Button *cur_button = (*toolbar)->buttons[i];
    if (!cur_button) continue;

    if (cur_button->type == EXIT) {
      cur_button->texture = LoadTexture(EXIT_BUTTON_IMG_PATH);
      cur_button->hover_texture = LoadTexture(EXIT_BUTTON_HOVER_IMG_PATH);
    } 
  }
}

void render_toolbar(Toolbar* toolbar) {

  // draw toolbar
  DrawRectangleRec(toolbar->bounds, toolbar->color);
  
  // render buttons
  Vector2 mouse_position = GetMousePosition();

  for (int i = 0; i<TOOLBAR_BUTTON_COUNT; i++) {
    Button* cur_button = toolbar->buttons[i];
    if (!cur_button) continue;
    
    bool is_hovering = CheckCollisionPointRec(mouse_position, cur_button->bounds);
    if (cur_button->type == EXIT) {
      if (is_hovering) {
        DrawTexture(cur_button->hover_texture, cur_button->bounds.x, cur_button->bounds.y, WHITE);
      } 
      else {
        DrawTexture(cur_button->texture, cur_button->bounds.x, cur_button->bounds.y, WHITE);
      }
    }

  }

}


