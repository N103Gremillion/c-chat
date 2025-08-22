#include "bootstrap_node.h"

int init_bootstrap_node() {


  struct addrinfo *addr_info_list = NULL; 
  
  if (get_bootstrap_node_address_list(&(addr_info_list)) != 0) {// this is a linked list 
    fprintf(stderr, "Failed to get bootstrap addresses\n");
    return -1;
  }

  struct sockaddr_in *ipv4_address = NULL; 
  
  if (get_bootstrap_node_address(addr_info_list, &ipv4_address) != 0) {
    fprintf(stderr, "Error: no IPv4 address found for this bootstrap node\n");
    return -1;
  }

  print_ipv4_address(ipv4_address);

  // free(addr_info_list);
  return 0;
}

int get_bootstrap_node_address_list(struct addrinfo **addr_info_list) {
  
  if (addr_info_list == NULL) return -1;

  // set it up to bind and accept other connections
  struct addrinfo hints;
  memset(&hints, 0, sizeof hints);
  hints.ai_family = BOOTSTRAP_FAMILY;
  hints.ai_socktype = BOOTSTRAP_SOCKET_TYPE;
  hints.ai_flags = AI_PASSIVE;

  char port_str[6];
  snprintf(port_str, sizeof(port_str), "%d", BOOTSTRAP_START_PORT);

  int status = getaddrinfo(NULL, port_str, &hints, addr_info_list);

  if (status != 0) {
    fprintf(stderr, "Issue setting up address info for server: %s\n", gai_strerror(status));
    *addr_info_list = NULL;
    return -1;
  }
  
  return 0;
}

int get_bootstrap_node_address(
  struct addrinfo *linked_list,
  struct sockaddr_in **ipv4_address 
) {

  struct addrinfo *cur_addrinfo = linked_list;

  while (cur_addrinfo != NULL) {
    if (cur_addrinfo->ai_family == AF_INET) { // IPv4
      *ipv4_address = (struct sockaddr_in *) cur_addrinfo->ai_addr;
      return 0;
    }
    cur_addrinfo = cur_addrinfo->ai_next;
  }

  return -1;
}

