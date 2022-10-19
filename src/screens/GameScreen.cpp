#include "global.h"
#include "screens/GameScreen.h"
#include "screens/game/GamePlayScreen.h"
#include "screens/game/GameOverScreen.h"

GameScreen::GameScreen() : Screen(SCREEN_GAME_NAME)
{
  this->fn_exit = [&]() -> void
  {
    this->SetSignal(SCREEN_SIGNAL_SET, SCREEN_MAIN_NAME);
  };
}

void GameScreen::Initialize()
{
  this->game_screen_store = new ScreenStore;
  this->game_screen_manager = new ScreenManager(this->game_screen_store);

  this->game_screen_store->AddScreen(new GamePlayScreen(&this->game));
  this->game_screen_store->AddScreen(new GameOverScreen(&this->game));

  ScreenSignal signal = {SCREEN_SIGNAL_SET, SCREEN_GAME_PLAY_NAME};
  this->game_screen_manager->SendSignal(signal);
}

void GameScreen::Terminate()
{
  delete (this->game_screen_store);
  delete (this->game_screen_manager);
  delete (this->game);
}

void GameScreen::Run()
{
  this->game_screen_manager->Run();
  this->fn_exit();
}
