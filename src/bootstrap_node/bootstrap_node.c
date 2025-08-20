#include "bootstrap_node.h"

int init_bootstrap_node() {
  struct addrinfo *addr_info_list = get_bootstrap_node_address_list(); // this is a linked list 

  struct sockaddr_in *ipv4_address = NULL; 

  if (get_bootstrap_node_address(addr_info_list, &ipv4_address) != 0) {
    fprintf(stderr, "Error: no IPv4 address found for this bootstrap node\n");
    exit(1);
  }

  print_ipv4_address(ipv4_address);

  // free(addr_info_list);

  return 0;
}

struct addrinfo* get_bootstrap_node_address_list() {
  
  struct addrinfo hints, *res;
  int status;

  // set it up to bind and accept other connections
  memset(&hints, 0, sizeof hints);
  hints.ai_family = BOOTSTRAP_FAMILY;
  hints.ai_socktype = BOOTSTRAP_SOCKET_TYPE;
  hints.ai_flags = AI_PASSIVE;

  char port_str[6];
  snprintf(port_str, sizeof(port_str), "%d", BOOTSTRAP_START_PORT);

  if ((status = getaddrinfo(NULL, port_str, &hints, &res))!= 0) {
    fprintf(stderr, "Issue setting up address info for server: %s\n", gai_strerror(status));
    exit(1);
  }
  return res;
}

int get_bootstrap_node_address(
  struct addrinfo *linked_list,
  struct sockaddr_in **ipv4_address 
) {

  struct addrinfo *cur_addrinfo = linked_list;

  while (cur_addrinfo != NULL) {
    // IPv4
    if (cur_addrinfo->ai_family == AF_INET) { 
      *ipv4_address = (struct sockaddr_in *) cur_addrinfo->ai_addr;
      return 0;
    }
    cur_addrinfo = cur_addrinfo->ai_next;
  }

  return -1;
}

