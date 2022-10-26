#include "global.h"
#include "config.h"
#include "interface/Interface.h"
#include "interface/MenuInterface.h"
#include "interface/TitleInterface.h"
#include "interface/WindowInterface.h"
#include "interface/TerminalInterface.h"
#include "screens/AboutScreen.h"

enum Triggers
{
  MAIN_MENU_CLOSE_GAME_CODE = 1,
};

unsigned int AboutScreen::COLUMNS_INDENT = 6;

#ifdef __linux__
unsigned int AboutScreen::COLOR_TITLE = 255;
unsigned int AboutScreen::COLOR_ITEM = 253;
#else
unsigned int AboutScreen::COLOR_TITLE = 97;
unsigned int AboutScreen::COLOR_ITEM = 37;
#endif

AboutScreen::AboutScreen() : Screen(SCREEN_ABOUT_NAME)
{
  this->screen_menu = new Menu;
  this->screen_menu->AddElement(MAIN_MENU_CLOSE_GAME_CODE, "Exit");

  this->data = {};

  this->AddRow("About developers:");
  this->AddRow("Author:", "Dmitry Tavern");
  this->AddRow("Author GitHub:", "https://github.com/dmitrytavern");
  this->AddSplit();
  this->AddRow("About application:");
  this->AddRow("Version:", APP_VERSION);
  this->AddRow("Repository:", "https://github.com/dmitrytavern/dtavern-game-2048");
  this->AddRow("Build:", APP_BUILD);
  this->AddRow("Platform:", APP_PLATFORM);
  this->AddRow("Architecture:", APP_ARCHITECTURE);

  this->CalculateWindowSize();
}

void AboutScreen::Render()
{
  this->CalculateSpaces();

  Interface::Title::OutputAboutTitle();
  Interface::Output("\n\n");

  for (int index = 0; index < this->data.size(); index++)
  {
    AboutItem item = this->data[index];
    std::string item_name = Interface::PaintText(item.color, item.column_name);
    std::string item_value = Interface::PaintText(item.color, item.column_value);

    Interface::OutputSpaces(this->window_spaces);
    Interface::Output(item_name);
    Interface::OutputSpaces(this->column_name_width - item.column_name.length());
    Interface::Output(item_value);
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

void AboutScreen::AddSplit()
{
  this->data.push_back({"", "", AboutScreen::COLOR_TITLE});
}

void AboutScreen::AddRow(std::string column_name)
{
  this->data.push_back({column_name, "", AboutScreen::COLOR_TITLE});
}

void AboutScreen::AddRow(std::string column_name, std::string column_value)
{
  this->data.push_back({column_name, column_value, AboutScreen::COLOR_ITEM});
}
