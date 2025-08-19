cmake_minimum_required(VERSION 3.23.2)
project(c-chat VERSION 1.0 LANGUAGES C)

# c files 
set (SOURCES
  src/main.c
  src/client/client.c
  src/server/server.c
)

add_executable(c-chat ${SOURCES})