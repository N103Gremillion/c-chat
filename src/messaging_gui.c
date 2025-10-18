#include "messaging_gui.h"

Message_GUI* init_messaging_gui() {
  Message_GUI* gui = (Message_GUI*) MALLOC(Message_GUI);
  return gui;
}