#include <sys/ioctl.h>
#include <unistd.h>
#include <string>
#include "../../include/ui/UI.h"

UI::UI()
{
  this->UpdateTerminalSize();

  cout << this->size->ws_col << endl;
}

void UI::Output(string text)
{
  cout << text << endl;
}

void UI::OutputCenter(string text, int text_length = 0)
{
  unsigned int length = text_length == 0 ? text.length() : text_length;

  this->OutputSpaces(this->size->ws_col / 2 - length / 2);
  cout << text << endl;
}

void UI::OutputSpaces(int count)
{
  for (int i = 0; i < count; i++)
    cout << " ";
}

void UI::OutputBorderTop(int count)
{
  for (int index = 0; index < count; index++)
    if (index == 0)
      cout << "┌";
    else if (index == count - 1)
      cout << "┐";
    else
      cout << "─";
  cout << endl;
}

void UI::OutputBorderBottom(int count)
{
  for (int index = 0; index < count; index++)
    if (index == 0)
      cout << "└";
    else if (index == count - 1)
      cout << "┘";
    else
      cout << "─";
  cout << endl;
}

void UI::UpdateTerminalSize()
{
  ioctl(STDOUT_FILENO, TIOCGWINSZ, this->size);
}

winsize *UI::GetTerminalSize()
{
  return this->size;
}
