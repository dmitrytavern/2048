#include "../../include/interface/BannerInterface.h"
#include "../../include/interface/Interface.h"
#include "../../include/interface/WindowInterface.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace Interface::Banner
{
void Output(string title, vector<string> actions)
{
  int actions_size = actions.size();
  int content_size = CalcContentSize(actions);
  int window_size = CalcWindowSize(content_size);
  int spaces_count = Interface::Window::CalcSpacesCount(window_size);

  Interface::OutputSpaces(spaces_count);
  Interface::Window::PrintBorderTopWithTitle(window_size, title);

  for (int index = 0; index < actions_size; index++)
  {
    Interface::OutputSpaces(spaces_count);
    Interface::Output(Interface::Window::BORDER_VERTICAL_CHAR);
    Interface::OutputSpaces(BORDER_WINDOW_PADDING);
    Interface::Output(actions[index]);
    Interface::OutputSpaces(content_size - actions[index].length());
    Interface::OutputSpaces(BORDER_WINDOW_PADDING);
    Interface::Output(Interface::Window::BORDER_VERTICAL_CHAR);
    Interface::Output();
  }

  Interface::OutputSpaces(spaces_count);
  Interface::Window::PrintBorderBottom(window_size);
}

static int CalcContentSize(vector<string> actions)
{
  int actions_size = actions.size();
  int max_content_length = 0;

  for (int index = 0; index < actions_size; index++)
  {
    int length = actions[index].length();
    max_content_length =
        length > max_content_length ? length : max_content_length;
  }

  return max_content_length;
}

static int CalcWindowSize(int content_size)
{
  return content_size + BORDER_WINDOW_PADDING * 2 + BORDER_SIZE * 2;
}
} // namespace Interface::Banner