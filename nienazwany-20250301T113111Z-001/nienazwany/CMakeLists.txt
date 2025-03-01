cmake_minimum_required(VERSION 3.5)

project(nienazwany LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(project_sources
    main.cpp
    organizm.cpp
    organizm.h
    ustawienia.h
    generatorlosowy.h
    generatorlosowy.cpp
    sasiedztwo.h
    sasiedztwo.cpp
    mieszkaniec.cpp
    mieszkaniec.h
    osobniki.h
    osobniki.cpp
    nisza.h
    nisza.cpp
    srodowisko.h
    srodowisko.cpp)

add_executable(nienazwany main.cpp
            organizm.cpp
            organizm.h
            ustawienia.h
            generatorlosowy.h
            generatorlosowy.cpp
            sasiedztwo.h
            sasiedztwo.cpp
            mieszkaniec.cpp
            mieszkaniec.h
            osobniki.h
            osobniki.cpp
            nisza.h
            nisza.cpp
            srodowisko.h
            srodowisko.cpp)

install(TARGETS nienazwany
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
