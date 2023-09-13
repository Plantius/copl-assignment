CC = g++

PARAMETERS = -Wall -Wextra -Wpedantic -Werror

SRC_DIR = ./src
OBJ_DIR = ./obj
INC_DIR = ./include
BIN_DIR = ./bin

INCLUDES = $(INC_DIR)/standard.h
OBJECTS = $(OBJ_DIR)/main.o $(OBJ_DIR)/standard.o  

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc $(INCLUDES)
	$(CC) $(PARAMETERS) -c -o $@ $<

$(BIN_DIR)/lambda: $(OBJECTS)
	$(CC) -o $@ $^

clean:
	rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/*