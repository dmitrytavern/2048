OUTPUT_CMAKE_DIRECTORY=build
OUTPUT_DIRECTORY=bin
OUTPUT_TEST_FILE=GameApplicationTests
OUTPUT_FILE=GameApplication

all: build compile

build:
	cmake . -B ./$(OUTPUT_CMAKE_DIRECTORY)/

compile:
	make -C ./$(OUTPUT_CMAKE_DIRECTORY)/

start:
	./$(OUTPUT_DIRECTORY)/$(OUTPUT_FILE)

test:
	./$(OUTPUT_DIRECTORY)/$(OUTPUT_TEST_FILE)

clean:
	rm -rf ./$(OUTPUT_DIRECTORY)/
	rm -rf ./$(OUTPUT_CMAKE_DIRECTORY)/
