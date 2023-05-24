#include <iostream>
#include "../../include/interface/Interface.h"
#include "../../include/interface/TitleInterface.h"
#include "../../include/interface/TerminalInterface.h"
#include "../../include/interface/WindowInterface.h"

namespace Interface::Title
{
  void OutputMainTitle()
  {
    if (BreakpointWidth(58))
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
    else if (BreakpointWidth(40))
    {
      Interface::Window::OutputCenter("    ____      _       __     ____ ");
      Interface::Window::OutputCenter("   / __ \\____| |     / /__  / __ \\");
      Interface::Window::OutputCenter("  / /_/ / __ \\ | /| / / _ \\/ /_/ /");
      Interface::Window::OutputCenter(" / ____/ /_/ / |/ |/ /  __/ _, _/ ");
      Interface::Window::OutputCenter("/_/    \\____/|__/|__/\\___/_/ |_|  ");
    }
    else
    {
      Interface::Window::OutputCenter("= PoWeR =");
    }
  }

  void OutputGameTitle()
  {
    if (BreakpointWidth(34))
    {
      Interface::Window::OutputCenter("       ___   ____  __ __  ____ ");
      Interface::Window::OutputCenter("    |__ \\ / __ \\/ // / ( __ )");
      Interface::Window::OutputCenter("    __/ // / / / // /_/ __  |");
      Interface::Window::OutputCenter("   / __// /_/ /__  __/ /_/ / ");
      Interface::Window::OutputCenter("/____/\\____/  /_/  \\____/");
    }
    else
    {
      Interface::Window::OutputCenter("= 2048 =");
    }
  }

  void OutputAboutTitle()
  {
    if (BreakpointWidth(40))
    {
      Interface::Window::OutputCenter("     ___    __                __ ");
      Interface::Window::OutputCenter("    /   |  / /_  ____  __  __/ /_");
      Interface::Window::OutputCenter("   / /| | / __ \\/ __ \\/ / / / __/");
      Interface::Window::OutputCenter("  / ___ |/ /_/ / /_/ / /_/ / /_  ");
      Interface::Window::OutputCenter("/_/  |_/_.___/\\____/\\__,_/\\__/");
    }
    else
    {
      Interface::Window::OutputCenter("= About =");
    }
  }

  static bool BreakpointWidth(int from)
  {
    return Interface::Terminal::GetWidth() >= from;
  }
}
