#include "utils.h"

void print_ipv4_address(struct sockaddr_in *ipv4_address) {
  char ipstr[INET_ADDRSTRLEN];
  inet_ntop(AF_INET, &(ipv4_address->sin_addr), ipstr, sizeof ipstr);

  // Convert port from network to host byte order
  unsigned short port = ntohs(ipv4_address->sin_port);
  printf("IPv4: %s:%d\n", ipstr, port);
}