GPP = g++
GPP_FLAGS = -lGL -lGLU -lglut -lm

SRC_DIR = src
BIN_DIR = bin

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

all: $(BIN_DIR)/prog

$(BIN_DIR)/prog: $(SRC_FILES)
	$(GPP) $^ $(GPP_FLAGS) -o $@

clean:
	rm bin/*

#g++ graph_test.cpp -lGL -lGLU -lglut -lm
