[< Back to docs](./readme.md)

# **How to compile this game?**

This game uses the CMake builder with already-ready presets. You only need to build it with the following tools:
  - Compile with [MS Visual Studio C++](#ms-visual-studio-c) (only Windows)
  - Compile with [Visual Studio Code](#visual-studio-code)
  - Compile [from linux termianl](#from-linux-termianl) (only Linux)
  - [Troubleshooting](#troubleshooting)

If you use windows, I recommend you use MS Visual Studio C++.

You can also build the game with other compilers or IDE, but in this file, I will use the methods that I personally tested. 
Okay, let's start!

## **MS Visual Studio C++**

1. Go to the [root](https://github.com/dmitrytavern/dtavern-game-2048) of the repository and download it. As zip or clone. (If you download the zip file, uncompress it)

1. Download and install [Visual Studio C++ Installer](https://visualstudio.microsoft.com/ru/vs/) from the official site.

1. Run installer. Select ***Desktop & Mobile*** -> ***Desktop development with C++***.

1. Press install and wait for when MS Visual Studio C++ will be installed on your PC.

1. Open MS Visual Studio C++

1. Click ***Open local folder*** and select the repository folder.

1. Select configuration in top bar ***Windows x64 Release***. (Or ***Windows x86 Release***, if you have 32-bit windows)

1. Press ***Build -> Build all*** or ***Ctrl + Shift + B***

1. If the compilation success ended, in repository folder will be created ***bin*** folder where you find the .exe file.

## **Visual Studio Code**

1. Download this repository.

1. Download Visual Studio Code on your os.

1. Download [C++ extension for VS Code](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) and [CMake Tools extension for VS Code](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools)

1. Now you need to select the CMake preset. Press ***Ctrl + Shift + P*** and enter ***>CMake: Select Configure Preset*** where will be displayed some presets. Use preset for you os.

1. Press ***Ctrl + Shift + P*** and enter ***>CMake: Build***.

1. If compilation success ended, in the repository direcotry will be created ***bin*** folder where you find the .exe file (or file without extention if you use UNIX).

## **From linux termianl**

1. Install ***cmake*** for your linux distribution

1. Clone this repository

```
git clone https://github.com/dmitrytavern/dtavern-game-2048

cd dtavern-game-2048
```

3. Type:

```
cmake . --preset <preset name>

make -C build/<preset name>
```
You can find all available presets in ***CMakePresets.json*** file.

4. If compilation success ended, in the repository direcotry will be created ***bin*** folder where you find the .exe file (or file without extention if you use UNIX).

##	**Troubleshooting**

If your compilation will be failed, open the [issue](https://github.com/dmitrytavern/dtavern-game-2048/issues/new).

## **P.S.**

If you have suggestions to improve the compilation instructions, open an [issue](https://github.com/dmitrytavern/dtavern-game-2048/issues/new) or make a pull request.