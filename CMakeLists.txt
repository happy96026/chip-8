cmake_minimum_required(VERSION 3.13)

project(Chip8 VERSION 0.1)

add_library(chip8_compiler_flags INTERFACE)
target_compile_features(chip8_compiler_flags INTERFACE cxx_std_17)
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(chip8_compiler_flags INTERFACE 
  "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)
list(APPEND EXTRA_LIBS chip8_compiler_flags)

add_subdirectory(src)

add_executable(Chip8 main.cpp)
target_link_libraries(Chip8 PUBLIC ${EXTRA_LIBS})
