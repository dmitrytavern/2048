project(2048_game)

add_library(UILib UI/UI.cpp)

add_library(GameLib
  Game/GameMatrix.cpp
  Game/GameController.cpp
  Game/GameUI.cpp
)

add_library(MenuLib
  Menu/Menu.cpp
  Menu/MenuAction.cpp
  Menu/MenuUI.cpp
)

add_library(ScreenLib
  Screen/Screen.cpp
  Screen/ScreenUI.cpp
)

add_executable(main main.cpp)

target_link_libraries(GameLib UILib)
target_link_libraries(MenuLib UILib)
target_link_libraries(main
  UILib
  GameLib
  MenuLib
  ScreenLib
)
