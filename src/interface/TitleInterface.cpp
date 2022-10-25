#include <iostream>
#include "interface/Interface.h"
#include "interface/TitleInterface.h"
#include "interface/TerminalInterface.h"
#include "interface/WindowInterface.h"

namespace Interface::Title
{
  void OutputMainTitle()
  {
    if (Interface::Terminal::GetWidth() >= 58)
    {
      Interface::Window::OutputCenter("$$$$$$$\\            $$\\      $$\\           $$$$$$$\\  ");
      Interface::Window::OutputCenter("$$  __$$\\           $$ | $\\  $$ |          $$  __$$\\ ");
      Interface::Window::OutputCenter("$$ |  $$ | $$$$$$\\  $$ |$$$\\ $$ | $$$$$$\\  $$ |  $$ |");
      Interface::Window::OutputCenter("$$$$$$$  |$$  __$$\\ $$ $$ $$\\$$ |$$  __$$\\ $$$$$$$  |");
      Interface::Window::OutputCenter("$$  ____/ $$ /  $$ |$$$$  _$$$$ |$$$$$$$$ |$$  __$$< ");
      Interface::Window::OutputCenter("$$ |      $$ |  $$ |$$$  / \\$$$ |$$   ____|$$ |  $$ |");
      Interface::Window::OutputCenter("$$ |      \\$$$$$$  |$$  /   \\$$ |\\$$$$$$$\\ $$ |  $$ |");
      Interface::Window::OutputCenter("\\__|       \\______/ \\__/     \\__| \\_______|\\__|  \\__|");
    }
    else
    {
      Interface::Window::OutputCenter("Power");
    }
  }

  void OutputGameTitle()
  {
    Interface::Window::OutputCenter("       ___   ____  __ __  ____ ");
    Interface::Window::OutputCenter("    |__ \\ / __ \\/ // / ( __ )");
    Interface::Window::OutputCenter("    __/ // / / / // /_/ __  |");
    Interface::Window::OutputCenter("   / __// /_/ /__  __/ /_/ / ");
    Interface::Window::OutputCenter("/____/\\____/  /_/  \\____/");
  }

  void OutputAboutTitle()
  {
    Interface::Window::OutputCenter("     ___    __                __ ");
    Interface::Window::OutputCenter("    /   |  / /_  ____  __  __/ /_");
    Interface::Window::OutputCenter("   / /| | / __ \\/ __ \\/ / / / __/");
    Interface::Window::OutputCenter("  / ___ |/ /_/ / /_/ / /_/ / /_  ");
    Interface::Window::OutputCenter("/_/  |_/_.___/\\____/\\__,_/\\__/");
  }
}
