#pragma once
#include <functional>
#include <iostream>

namespace Interface::Terminal
{
void Clear();
void HideCursor();
void ShowCursor();
unsigned int GetWidth();
unsigned int GetHeight();

#ifdef _WIN32
void SetWindowSize(int width, int height);
void DisableWindowScrollbar();
#endif
} // namespace Interface::Terminal

#ifdef __linux__
namespace Interface::Terminal
{
static std::function<void(int)> resize_handler;
static bool resize_handler_exists;

void SetResizeHandler(std::function<void(int)> handler);
void ClearResizeHandler();
void ActivateResizeListener();
static void CallResizeHandler(int signum);
} // namespace Interface::Terminal
#endif