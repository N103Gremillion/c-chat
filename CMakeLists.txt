cmake_minimum_required(VERSION 3.23.2)
project(c-chat VERSION 1.0 LANGUAGES C)

# Add include folder
include_directories(include)

# c files 
set (SOURCES
  src/main.c
  src/chat_node.c
  src/bootstrap_node.c
  src/messaging_gui.c
  src/utils.c
)

add_executable(c-chat ${SOURCES})

# setup raylib
find_package(raylib REQUIRED)
target_link_libraries(c-chat raylib)

