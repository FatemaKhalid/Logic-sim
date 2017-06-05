cmake_minimum_required(VERSION 3.7)
project(Logic_Sim)

set(CMAKE_CXX_STANDARD 11)
file(GLOB Actions
        "*.h"
        "*.cpp"
        )

file(GLOB GUI
        "*.h"
        "*.cpp"
        )
file(GLOB Components
        "*.h"
        "*.cpp"
        )
file(GLOB CMUgraphicsLib
        "*.h"
        "*.cpp"
        )
file(GLOB SOURCE_FILES
        "main.cpp"
        "redo.cpp"
        "undo.cpp"
        "select_area.cpp"
        "ApplicationManager.cpp"
        )

set(SOURCE_FILES Defs.H  Actions GUI Components CMUgraphicsLib)
add_executable(Logic_Sim ${Actions} ${GUI} ${Components} ${SOURCE_FILES} )
