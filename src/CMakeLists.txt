project(DTavernGameApplication)

add_library(Core
  core/Core.cpp
  core/CoreMatrix.cpp
  core/CoreScore.cpp
  core/GameMatrix.cpp
)

add_library(Interface
  interface/Interface.cpp
  interface/BannerInterface.cpp
  interface/MatrixInterface.cpp
  interface/WindowInterface.cpp
  interface/DialogInterface.cpp
  interface/TerminalInterface.cpp
)

add_library(ScreenLibrary
  libraries/Screen/Screen.cpp
  libraries/Screen/ScreenStore.cpp
  libraries/Screen/ScreenManager.cpp
)

add_executable(GameApplication
  GameApplication.cpp
  screens/MainScreen.cpp
  screens/GameScreen.cpp
  screens/ExitScreen.cpp
  screens/game/GamePlayScreen.cpp
  screens/game/GameOverScreen.cpp
)

target_link_libraries(GameApplication
  Core
  Interface
  ScreenLibrary
)
