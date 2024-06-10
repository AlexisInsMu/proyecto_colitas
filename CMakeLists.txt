cmake_minimum_required(VERSION 3.21)
project(WindowsExampl)


# set the C standard to C99
set(CMAKE_C_STANDARD 99)
# Add an executable to the project using main.cpp
add_executable(${PROJECT_NAME} src/main_grafico.c)

# Link the executable to the Windows SDK libraries
target_link_libraries(${PROJECT_NAME} PRIVATE WindowsApp)
# Include the header files directory

# Add additional source files to the project
target_sources(${PROJECT_NAME} PRIVATE src/estilos.c src/graficos.c)

# Add additional source files to the project

# Specify that we are building a Windows application
# This is optional and can be omitted if you're building a console application
# add_definitions(-DUNICODE -D_UNICODE)