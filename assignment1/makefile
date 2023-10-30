CC = g++

PARAMETERS = -Wall -Wextra -Wpedantic -g

SRC_DIR = ./src
OBJ_DIR = ./obj
INC_DIR = ./include
BIN_DIR = ./bin

INCLUDES = $(INC_DIR)/standard.h $(INC_DIR)/parser.h $(INC_DIR)/token.h $(INC_DIR)/tokenId.h $(INC_DIR)/error.h
OBJECTS = $(OBJ_DIR)/main.o $(OBJ_DIR)/standard.o $(OBJ_DIR)/parser.o $(OBJ_DIR)/token.o $(OBJ_DIR)/error.o

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc $(INCLUDES)
	$(CC) $(PARAMETERS) -c -o $@ $<

$(BIN_DIR)/lambda: $(OBJECTS)
	$(CC) -o $@ $^

clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/*

build: $(BIN_DIR)/lambda
	
run: build
	$(BIN_DIR)/lambda ./positives.txt