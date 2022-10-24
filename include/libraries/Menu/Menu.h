#pragma once
#include <iostream>
#include <vector>

struct MenuElement
{
  int code;
  std::string name;
};

class Menu
{
private:
  std::vector<MenuElement> elements;
  int currect_element_index;

public:
  Menu();
  int GetActiveElementIndex();
  void SetActiveElementIndex(int index);
  void AddElement(int code, std::string name);
  std::vector<MenuElement> GetElements();
};
