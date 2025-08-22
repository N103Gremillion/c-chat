#include <stdlib.h>
#include <stdio.h>
#include "./bootstrap_node/bootstrap_node.h"

int main(int argc, char* argv[]) {

  if (init_bootstrap_node() != 0) {
    fprintf(stderr, "Bootstrap node initialization failed. Exiting. \n");
    return 1;
  }

  return 0;
}