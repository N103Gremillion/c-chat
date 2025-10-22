#ifndef UTILS_H
#define UTILS_H

#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <stddef.h>
#include <stdlib.h>

void print_ipv4_address(struct sockaddr_in *ipv4_address);
void* safe_malloc(size_t bytes_to_malloc);

#define MALLOC(type, count) ((void*)safe_malloc(sizeof(type) * count));

#endif