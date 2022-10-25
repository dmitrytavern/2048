#include "global.h"
#include "interface/Interface.h"
#include "interface/MenuInterface.h"
#include "interface/WindowInterface.h"
#include "interface/TerminalInterface.h"
#include "screens/AboutScreen.h"

enum Triggers
{
  MAIN_MENU_CLOSE_GAME_CODE = 1,
};

AboutScreen::AboutScreen() : Screen(SCREEN_ABOUT_NAME)
{
  this->screen_menu = new Menu;
  this->screen_menu->AddElement(MAIN_MENU_CLOSE_GAME_CODE, "Exit");

  this->data = {};
  this->data.push_back({"About developers:", ""});
  this->data.push_back({"Author:", "Dmitry Tavern"});
  this->data.push_back({"Author GitHub:", "https://github.com/dmitrytavern"});
}

void AboutScreen::Render()
{
  const int columns_indent = 12;
  int data_size = this->data.size();

  Interface::Window::OutputVerticalAlign(data_size + 2);

  int max_column_name_length = 0;
  int max_column_value_length = 0;
  for (int index = 0; index < data_size; index++)
  {
    AboutItem item = this->data[index];
    max_column_name_length = (item.column_name.length() > max_column_name_length) ? item.column_name.length() : max_column_name_length;
    max_column_value_length = (item.column_value.length() > max_column_value_length) ? item.column_name.length() : max_column_value_length;
  }

  int window_size = max_column_name_length + max_column_value_length + columns_indent;
  int spaces_count = Interface::Window::CalcSpacesCount(window_size);

  for (int index = 0; index < data_size; index++)
  {
    AboutItem item = this->data[index];
    Interface::OutputSpaces(spaces_count);
    Interface::Output(item.column_name);
    Interface::OutputSpaces(max_column_name_length + columns_indent - item.column_name.length());
    Interface::Output(item.column_value);
    Interface::Output();
  }

  Interface::Output();
  Interface::Menu::Output(this->screen_menu);

  Interface::Terminal::Clear();
  Interface::Print();
}

void AboutScreen::Run()
{
  const int code = Interface::Menu::Activate(this->screen_menu);

  switch (code)
  {
  case MAIN_MENU_CLOSE_GAME_CODE:
    this->SetSignal(SCREEN_SIGNAL_SET, SCREEN_MAIN_NAME);
    break;
  }
}
