cmake_minimum_required(VERSION 3.14)
project(ved C)

set(CMAKE_C_STANDARD 99)

include_directories(/usr/local/opt/ncurses/include)

link_directories(/usr/local/Cellar/ncurses/6.2/lib/)

link_libraries(ncursesw)

add_executable(ved ved.c libs/tui.h libs/menu.h)
#add_executable(menuejemplo menuejemplo.c libs/menu.h)
