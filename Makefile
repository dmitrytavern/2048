OUTPUT_CMAKE_DIRECTORY=build
OUTPUT_DIRECTORY=bin
OUTPUT_FILE=main

all: build compile

build:
	cmake . -B ./$(OUTPUT_CMAKE_DIRECTORY)/

compile:
	make -C ./$(OUTPUT_CMAKE_DIRECTORY)/

start:
	./$(OUTPUT_DIRECTORY)/$(OUTPUT_FILE)

clean:
	rm -rf ./$(OUTPUT_DIRECTORY)/
	rm -rf ./$(OUTPUT_CMAKE_DIRECTORY)/
