add_library(Chip8Module OBJECT chip8.cpp)
target_link_libraries(Chip8Module PRIVATE chip8_compiler_flags)
list(APPEND EXTRA_LIBS Chip8Module)
