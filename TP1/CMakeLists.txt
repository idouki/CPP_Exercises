add_executable(hello-world
    helloworld.cpp
)

target_compile_options(hello-world PRIVATE
    -Wall
    -Wextra
    -Werror
)