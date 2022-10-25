#include <vector>
#include "libraries/Menu/Menu.h"

using namespace std;

Menu::Menu()
{
  this->elements = {};
  this->currect_element_index = 0;
}

int Menu::GetActiveElementIndex()
{
  return this->currect_element_index;
}

void Menu::SetActiveElementIndex(int index)
{
  int size = this->elements.size();

  if (index < 0)
    index = 0;

  if (index >= size)
    index = size - 1;

  this->currect_element_index = index;
}

void Menu::AddElement(int code, string name)
{
  int currect_size = this->elements.size();
  this->elements.push_back(MenuElement());
  this->elements[currect_size].code = code;
  this->elements[currect_size].name = name;
}

vector<MenuElement> Menu::GetElements()
{
  return this->elements;
}
