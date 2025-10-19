#ifndef BOOTSTRAP_NODE_H
#define BOOTSTRAP_NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#include "utils.h"

#define BOOTSTRAP_START_PORT 8080
#define BOOTSTRAP_MAX_NODES 5
#define BOOTSTRAP_MAX_CONNECTIONS 100
#define BOOTSTRAP_FAMILY AF_UNSPEC // makes it fetch both IPV4 and IPV6
#define BOOTSTRAP_SOCKET_TYPE SOCK_STREAM // used tcp under the hood

// setup a basic socket to listen for incomming requests and add the fds you want to poll for
typedef struct BootstrapNode {
  char *loopback_ip;
  char *lan_ip;
  char *public_ip;
  struct sockaddr_in *ipv4_address;
} BootstrapNode;

int get_bootstrap_node_address(
  struct addrinfo *linked_list,
  struct sockaddr_in **ipv4_address
);

BootstrapNode* init_bootstrap_node();
struct addrinfo* get_bootstrap_node_address_list();

#endif