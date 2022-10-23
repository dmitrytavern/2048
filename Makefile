OUTPUT_CMAKE_DIRECTORY=build
OUTPUT_DEBUG_CMAKE_DIRECTORY=linux-debug
OUTPUT_RELEASE_CMAKE_DIRECTORY=linux-release
OUTPUT_CMAKE_DIRECTORY=build
OUTPUT_DIRECTORY=bin
OUTPUT_TEST_FILE=GameApplicationTests
OUTPUT_FILE=GameApplication

all: release

# Release
release: build-release compile-release

build-release:
	rm -rf ./$(OUTPUT_DIRECTORY)/
	cmake . -B ./$(OUTPUT_CMAKE_DIRECTORY)/${OUTPUT_RELEASE_CMAKE_DIRECTORY}/ -DCMAKE_BUILD_TYPE=Release

compile-release:
	make -C ./$(OUTPUT_CMAKE_DIRECTORY)/${OUTPUT_RELEASE_CMAKE_DIRECTORY}/

# Debug
debug: build-debug compile-debug

build-debug:
	rm -rf ./$(OUTPUT_DIRECTORY)/
	cmake . -B ./$(OUTPUT_CMAKE_DIRECTORY)/${OUTPUT_DEBUG_CMAKE_DIRECTORY}/ -DCMAKE_BUILD_TYPE=Debug

compile-debug:
	make -C ./$(OUTPUT_CMAKE_DIRECTORY)/${OUTPUT_DEBUG_CMAKE_DIRECTORY}/

start:
	./$(OUTPUT_DIRECTORY)/$(OUTPUT_FILE)

test:
	./$(OUTPUT_DIRECTORY)/$(OUTPUT_TEST_FILE)

clean:
	rm -rf ./$(OUTPUT_DIRECTORY)/
	rm -rf ./$(OUTPUT_CMAKE_DIRECTORY)/
