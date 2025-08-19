#include "server.h"

int init_server_address(struct addrinfo *addr_info) {
  struct addrinfo hints;

  // set it up to bind and accept other connections
  memset(&hints, 0, sizeof hints);
  hints.ai_family = SERVER_FAMILY;
  hints.ai_socktyp = SERVER_SOCKET_TYPE;
  hints.ai_flags = AI_PASSIVE;

  if (getaddrinfo(NULL, SERVER_PORT, &hints, ) != 0) {
    fprintf(stderr, "Issue setting up address info for server.", gai_strerror(status));
    exit(1);
  }

}

int init_server() {
  puts("Hello World.");
  return 0;
}