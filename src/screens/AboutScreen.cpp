#include "global.h"
#include "config.h"
#include "interface/Interface.h"
#include "interface/MenuInterface.h"
#include "interface/WindowInterface.h"
#include "interface/TerminalInterface.h"
#include "screens/AboutScreen.h"

enum Triggers
{
  MAIN_MENU_CLOSE_GAME_CODE = 1,
};

unsigned int AboutScreen::COLUMNS_INDENT = 6;

AboutScreen::AboutScreen() : Screen(SCREEN_ABOUT_NAME)
{
  this->screen_menu = new Menu;
  this->screen_menu->AddElement(MAIN_MENU_CLOSE_GAME_CODE, "Exit");

  this->data = {};
  this->data.push_back({"About developers:", ""});
  this->data.push_back({"Author:", "Dmitry Tavern"});
  this->data.push_back({"Author GitHub:", "https://github.com/dmitrytavern"});
  this->data.push_back({"", ""});
  this->data.push_back({"About application:", ""});
  this->data.push_back({"Version:", APP_VERSION});

  this->CalculateWindowSize();
}

void AboutScreen::Render()
{
  this->CalculateSpaces();

  Interface::Window::OutputCenter("     ___    __                __ ");
  Interface::Window::OutputCenter("    /   |  / /_  ____  __  __/ /_");
  Interface::Window::OutputCenter("   / /| | / __ \\/ __ \\/ / / / __/");
  Interface::Window::OutputCenter("  / ___ |/ /_/ / /_/ / /_/ / /_  ");
  Interface::Window::OutputCenter("/_/  |_/_.___/\\____/\\__,_/\\__/");
  Interface::Output("\n\n");

  for (int index = 0; index < this->data.size(); index++)
  {
    AboutItem item = this->data[index];
    Interface::OutputSpaces(this->window_spaces);
    Interface::Output(item.column_name);
    Interface::OutputSpaces(this->column_name_width - item.column_name.length());
    Interface::Output(item.column_value);
    Interface::Output();
  }

  Interface::Output("\n\n");
  Interface::Menu::Output(this->screen_menu);

  Interface::Window::AlignVertically();
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

void AboutScreen::CalculateSpaces()
{
  int window_size = this->column_name_width + this->column_value_width;
  this->window_spaces = Interface::Window::CalcSpacesCount(window_size);
}

void AboutScreen::CalculateWindowSize()
{
  int data_size = this->data.size();
  int max_column_name_length = 0;
  int max_column_value_length = 0;

  for (int index = 0; index < data_size; index++)
  {
    AboutItem item = this->data[index];
    max_column_name_length = (item.column_name.length() > max_column_name_length) ? item.column_name.length() : max_column_name_length;
    max_column_value_length = (item.column_value.length() > max_column_value_length) ? item.column_value.length() : max_column_value_length;
  }

  this->column_name_width = max_column_name_length + AboutScreen::COLUMNS_INDENT;
  this->column_value_width = max_column_value_length;
}
