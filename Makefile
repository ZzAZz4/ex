CXX := g++
CXX_FLAGS := -std=c++17 -O2
SRC := main.cpp
SRC_DIR := ./src
INC_DIR := ./include
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
BIN := a.out

# just wanted to have a consistent rm command and i ended up with this mess
ifeq '$(findstring ;,$(PATH))' ';'
	HOST_OS := Windows
else
	HOST_OS := $(shell sh -c 'uname 2>/dev/null || echo Unknown')
endif

ifeq ($(HOST_OS),Windows)
	RM_COMMAND := del /Q /S
endif
ifeq ($(HOST_OS),Linux)
	RM_COMMAND := rm -rf
endif

make:
	$(CXX) -o $(BIN) $(CXX_FLAGS) $(SRC) $(SRC_FILES)

clean:
	$(RM_COMMAND) $(BIN)