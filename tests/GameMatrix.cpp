#include <catch2/catch_test_macros.hpp>
#include "../include/core/GameMatrix.h"

TEST_CASE("GameMatrix correctly swiping matrix", "[GameMatrix]")
{
  SECTION("swipe top")
  {
    GameMatrix matrix(4);

    matrix.GetMatrix()[2][2] = 2;

    matrix.SwipeUp();

    REQUIRE(matrix.GetMatrix()[2][2] == 0);
    REQUIRE(matrix.GetMatrix()[0][2] == 2);
  }

  SECTION("swipe left")
  {
    GameMatrix matrix(4);

    matrix.GetMatrix()[2][2] = 2;

    matrix.SwipeLeft();

    REQUIRE(matrix.GetMatrix()[2][2] == 0);
    REQUIRE(matrix.GetMatrix()[2][0] == 2);
  }

  SECTION("swipe down")
  {
    GameMatrix matrix(4);

    matrix.GetMatrix()[2][2] = 2;

    matrix.SwipeDown();

    REQUIRE(matrix.GetMatrix()[2][2] == 0);
    REQUIRE(matrix.GetMatrix()[3][2] == 2);
  }

  SECTION("swipe right")
  {
    GameMatrix matrix(4);

    matrix.GetMatrix()[2][2] = 2;

    matrix.SwipeRight();

    REQUIRE(matrix.GetMatrix()[2][2] == 0);
    REQUIRE(matrix.GetMatrix()[2][3] == 2);
  }
}

TEST_CASE("GameMatrix correctly merge cells", "[GameMatrix]")
{
  SECTION("one merge action")
  {
    GameMatrix matrix(4);

    matrix.GetMatrix()[0][0] = 2;
    matrix.GetMatrix()[0][1] = 2;

    matrix.SwipeLeft();

    REQUIRE(matrix.GetMatrix()[0][0] == 4);
    REQUIRE(matrix.GetMatrix()[0][1] == 0);
  }

  SECTION("two merge action")
  {
    GameMatrix matrix(4);

    matrix.GetMatrix()[0][0] = 2;
    matrix.GetMatrix()[0][1] = 2;
    matrix.GetMatrix()[0][2] = 2;
    matrix.GetMatrix()[0][3] = 2;

    matrix.SwipeLeft();

    REQUIRE(matrix.GetMatrix()[0][0] == 8);
    REQUIRE(matrix.GetMatrix()[0][1] == 0);
    REQUIRE(matrix.GetMatrix()[0][2] == 0);
    REQUIRE(matrix.GetMatrix()[0][3] == 0);
  }
}
