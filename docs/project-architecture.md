[< Back to docs](../)

# **Game Architecture**

Table of Contents:
- [How the code is divided?](#how-the-code-is-divided)
  - [Core](#core)
  - [Interface](#interface)
  - [Libraries](#libraries)
  - [Main](#main)
- [How does the game work?](#how-does-the-game-work)

## **How the code is divided?**

All code is divided into several main parts:
  - [Core](#core) - the game logic
  - [Interface](#interface) - the game ui
  - [Libraries](#libraries) - game libraries
  - [Main](#main) - the entry point of game

### **Core**

This is the whole logic of the game. It is divided into the main file **Core.cpp**, where there are high-level functions that connect one logic to another.

**Not recommended:** To link one logic to another not in Core.cpp. They must be independent of each other.

**Not recommended:** To use simple libraries that you can write yourself.

**Forbidden:** To use logic for drawing the interface in it.

### **Interface**

This is an interface rendering module. Unlike Core, files have a strong connection.

The rendering itself works as follows: we have two functions, **Output** and **Print**.
- Output - adds a line to the buffer
- Print - prints the buffer to the screen and clears it

All functions in Interface*.cpp use Output, so it's up to the user to decide when to output the buffer.

**Not recommended:** To use complex arguments in functions such as class instances or libraries.

**Forbidden:** To use functions to display information on the screen, bypassing Output and Print

### **Libraries**

This is a folder in which parts separate from the game are entered. Their main difference is that they can be used in other programs.

**Forbidden:** Have any dependency on Core, Interface or any other part of the project.

### **Main**

Project entry point. It collects Core, Interface, Libraries into one.

**Not recommended:** To contain project logic that can be moved to Core.

## **How does the game work?**

### **1. The game is divided into screens.**

Screen is a class that connects logic and UI.

### **2. Each screen cannot interact with the other, they are completely independent.**

Although they are separate classes and can be chained, it is strongly discouraged to do so.

### **3. Screens can be nested within another screen.**

This works because their manager and store is not a Singleton class. Therefore, one screen can store storage for several sub-screens.

Additionally, since the managers and store are not related to the root, you can use the screens that were initialized above and pass other data to them, for example.

### **4. The current screen is the only one currently being rendered, even if it is nested.**

Even if a screen and its manager are nested within another screen, the last active manager and its active screen will be used.

Of course, you can make the child and parent screens work at once, but this will mean that the child class will be re-initialized and cleared every cycle. And also, if a re-render of the screen is called from outside, only the child will be drawn.