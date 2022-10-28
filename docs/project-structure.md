[< Back to docs](../)

# **Game directory structure**

Currect structure:

```
dtavern-game-2048/
  bin/
  build/
  docs/
  include/
  resources/
  src/
    core/
    interface/
    libraries/
    screens/
    CMakeLists.txt
    GameApplication.cpp
  tests/
    [folder]
      - [tests].cpp
      - CMakeLists.txt
    CMakeLists.txt
  CMakeLists.txt
  CMakePresets.json
```

## **bin/**

This directory needs to store artifacts such as compiled code. By default, ignored by git, creating automatically, after CMake build.

## **build/**

This directory needs to store CMake preset builds. By default, ignored by git, creating automatically, after CMake build.

## **docs/**

This directory needs to store documentation by project.

## **include/**

This directory needs to store the header files of the project

## **resources/**

This directory needs to store the resources of the project. Picture or icons.

## **src/**

This directory needs to store the project code

- core - contains the logic of the game
- interface - contains the logic of the game UI
- libraries - contains libraires of the game
- screens - contains screens of the game

## **tests/**

This directory needs to store the project tests
