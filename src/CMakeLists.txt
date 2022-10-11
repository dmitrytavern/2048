project(2048_game)

add_library(UILibrary libraries/UI/UI.cpp)

add_library(GameLibrary
  libraries/Game/GameMatrix.cpp
  libraries/Game/GameController.cpp
  libraries/Game/GameUI.cpp
)

add_library(MenuLibrary
  libraries/Menu/Menu.cpp
  libraries/Menu/MenuAction.cpp
  libraries/Menu/MenuFactory.cpp
  libraries/Menu/MenuUI.cpp
)

add_library(ScreenLibrary
  libraries/Screen/Screen.cpp
  libraries/Screen/ScreenFactory.cpp
  libraries/Screen/ScreenManager.cpp
)

add_executable(main main.cpp)

target_link_libraries(GameLibrary UILibrary)
target_link_libraries(MenuLibrary UILibrary)
target_link_libraries(main
  UILibrary
  GameLibrary
  MenuLibrary
  ScreenLibrary
)
