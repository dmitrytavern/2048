add_library(Core
  core/Core.cpp
  core/CoreMatrix.cpp
  core/CoreScore.cpp
  core/GameMatrix.cpp
)

add_library(Interface
  interface/Interface.cpp
  interface/MenuInterface.cpp
  interface/TitleInterface.cpp
  interface/BannerInterface.cpp
  interface/MatrixInterface.cpp
  interface/WindowInterface.cpp
  interface/DialogInterface.cpp
  interface/TerminalInterface.cpp
)

add_library(MenuLibrary
  libraries/Menu/Menu.cpp
)

add_library(ScreenLibrary
  libraries/Screen/Screen.cpp
  libraries/Screen/ScreenStore.cpp
  libraries/Screen/ScreenManager.cpp
)

add_executable(${APP_PROJECT_NAME}
  GameApplication.cpp
  screens/MainScreen.cpp
  screens/GameScreen.cpp
  screens/ExitScreen.cpp
  screens/AboutScreen.cpp
  screens/game/GamePlayScreen.cpp
  screens/game/GameOverScreen.cpp
  "../resources/appicon.rc"
)

target_link_libraries(${APP_PROJECT_NAME}
  Core
  Interface
  MenuLibrary
  ScreenLibrary
)
