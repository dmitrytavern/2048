#pragma once
#include "../../include/interface/Interface.h"
#include <iostream>
#include <vector>

namespace Interface::Banner
{
const int BORDER_SIZE = 1;
const int BORDER_WINDOW_PADDING = 3;

void Output(std::string title, std::vector<std::string> actions);
static int CalcContentSize(std::vector<std::string>);
static int CalcWindowSize(int content_size);
} // namespace Interface::Banner
