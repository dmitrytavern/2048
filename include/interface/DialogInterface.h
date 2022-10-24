#pragma once

namespace Interface::Dialog
{
#ifdef __linux__
  const int KEY_ENTER = 10;
#else
  const int KEY_ENTER = 13;
#endif

  const int KEY_UP = 72;
  const int KEY_DOWN = 80;
  const int KEY_LEFT = 75;
  const int KEY_RIGHT = 77;

  const int CHAR_W = 119;
  const int CHAR_W_UPPER = 87;
  const int CHAR_A = 97;
  const int CHAR_A_UPPER = 65;
  const int CHAR_S = 115;
  const int CHAR_S_UPPER = 83;
  const int CHAR_D = 100;
  const int CHAR_D_UPPER = 68;
  const int CHAR_E = 101;
  const int CHAR_E_UPPER = 69;
  const int CHAR_Y = 121;
  const int CHAR_Y_UPPER = 89;
  const int CHAR_N = 110;
  const int CHAR_N_UPPER = 78;

  const int CHAR_1 = 49;
  const int CHAR_0 = 48;

  int GetCharCode();

  bool GetComfirm();
}
