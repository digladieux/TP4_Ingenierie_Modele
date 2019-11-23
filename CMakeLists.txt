cmake_minimum_required(VERSION 3.7.2)

project(TP3_Ingenierie_Model)

set(CMAKE_C_FLAGS "-g")

set(HEADERS
header/MetaObjetGraphique.h
header/MetaCercle.h
header/MetaRectangle.h
header/ObjetGraphique.h
header/Cercle.h
header/Rectangle.h
)

set(SOURCES
src/MetaObjetGraphique.c
src/MetaRectangle.c
src/MetaCercle.c

)

set(CMAKE_C_CPPCHECK "cppcheck")
add_custom_target(
        cppcheck
        COMMAND /usr/bin/cppcheck
        --enable=warning,performance,portability,information,missingInclude
        --std=c++17
        --library=qt.cfg
        --template="[{severity}][{id}] {message} {callstack} \(On {file}:{line}\)"
        --verbose
        --quiet
        ${ALL_SOURCE_FILES}
)

add_executable(exe src/main.c ${SOURCES} ${HEADERS})