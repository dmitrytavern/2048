project(DTavernGameApplication)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	Include(FetchContent)

	FetchContent_Declare(
	  Catch2
	  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
	  GIT_TAG        v3.0.1 # or a later release
	)

	FetchContent_MakeAvailable(Catch2)

	add_executable(GameApplicationTests
	  GameMatrix.cpp
	  ../src/core/GameMatrix.cpp
	)

	target_link_libraries(GameApplicationTests PRIVATE Catch2::Catch2WithMain)
endif()

