#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_CONNECTIONS 100
#define SERVER_PORT "8080"
#define SERVER_FAMILY AF_UNSPEC // either IPv4 or IPv6
#define SERVER_SOCKET_TYPE SOCK_STREAM // uses TCP under the hood so good for message handling


// setup a basic socket to listen for incomming requests and add the fds you want to poll for
typedef struct Server {
} Server;

int init_server();
int init_server_address();