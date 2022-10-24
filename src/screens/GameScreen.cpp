#include "global.h"
#include "core/Core.h"
#include "screens/GameScreen.h"
#include "screens/game/GamePlayScreen.h"
#include "screens/game/GameOverScreen.h"

void GameScreen::Initialize()
{
  this->game_screen_store = new ScreenStore;
  this->game_screen_manager = new ScreenManager(this->game_screen_store);

  this->game_screen_store->AddScreen(new GamePlayScreen(SCREEN_GAME_PLAY_NAME));
  this->game_screen_store->AddScreen(new GameOverScreen(SCREEN_GAME_OVER_NAME));

  ScreenSignal signal = {SCREEN_SIGNAL_SET, SCREEN_GAME_PLAY_NAME};
  this->game_screen_manager->SendSignal(signal);
}

void GameScreen::Terminate()
{
  Core::ToFinishGame();
  delete (this->game_screen_store);
  delete (this->game_screen_manager);
}

void GameScreen::Run()
{
  this->game_screen_manager->Run();
  this->SetSignal(SCREEN_SIGNAL_SET, SCREEN_MAIN_NAME);
}
