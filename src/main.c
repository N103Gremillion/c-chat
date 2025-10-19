#include <stdlib.h>
#include <stdio.h>
#include "bootstrap_node.h"
#include "gui.h"

int main(int argc, char* argv[]) {
  GUI *gui = init_gui();
  setup_messaging_window(gui);
  return 0;
}