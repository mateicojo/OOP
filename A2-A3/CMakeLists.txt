cmake_minimum_required(VERSION 3.23)
project(A2_A3 C)

set(CMAKE_C_STANDARD 11)

add_executable(A2_A3
        main.c Material.c Repo.c Services.c UI.c Tests.c Tests.h ../A4-A5/DynArray.cpp ../A4-A5/DynArray.h)