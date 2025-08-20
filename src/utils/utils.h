#ifndef UTILS_H
#define UTILS_H

#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>

void print_ipv4_address(struct sockaddr_in *ipv4_address);

#endif