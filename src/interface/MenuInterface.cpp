#include <string>
#include <vector>
#include "interface/Interface.h"
#include "interface/WindowInterface.h"
#include "interface/MenuInterface.h"
#include "interface/DialogInterface.h"
#include "libraries/Menu/Menu.h"

using _Menu = Menu;
using namespace std;

namespace Interface::Menu
{
  void Output(_Menu *menu)
  {
    vector<MenuElement> elements = menu->GetElements();
    int active_element_index = menu->GetActiveElementIndex();

    for (int index = 0; index < elements.size(); index++)
    {
      const int color = index == active_element_index ? ACTIVE_ELEMENT_COLOR : ELEMENT_COLOR;
      string title = Interface::PaintText(color, elements[index].name);

      Interface::Window::OutputCenter(title, elements[index].name.length());

      if (index < elements.size() - 1)
        Interface::Output();
    }
  }

  int Activate(_Menu *menu)
  {
    vector<MenuElement> elements = menu->GetElements();
    int active_element_index = menu->GetActiveElementIndex();
    int selected_element_code = -1;

    const int code = Interface::Dialog::GetCharCode();

    switch (code)
    {
    case Interface::Dialog::KEY_UP:
      active_element_index--;
      break;

    case Interface::Dialog::KEY_DOWN:
      active_element_index++;
      break;

    case Interface::Dialog::KEY_ENTER:
    case Interface::Dialog::KEY_RIGHT:
      selected_element_code = elements[active_element_index].code;
      break;
    }

    menu->SetActiveElementIndex(active_element_index);

    return selected_element_code;
  }
}
