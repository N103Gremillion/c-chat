cmake_minimum_required(VERSION 3.23.2)
project(c-chat VERSION 1.0 LANGUAGES C)

# c files 
set (SOURCES
  src/main.c
  src/chat_node/chat_node.c
  src/bootstrap_node/bootstrap_node.c
  src/utils/utils.c
)

add_executable(c-chat ${SOURCES})