#pragma once
#include "CoreMatrix.h"
#include <iostream>

namespace Core
{
void ToStartGame();
void ToFinishGame();
void ToMove(Core::Matrix::SwipeDirections direction);

static void Next();
static int GenerateNumber();
} // namespace Core
