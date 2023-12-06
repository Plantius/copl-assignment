CC = g++

PARAMETERS = -Wall -Wextra -Wpedantic -g

TARGET = lambda
SRC_DIR = ./src
INC_DIR = ./include

OUT_FILE = out

INCLUDES = $(INC_DIR)/standard.h \
		   $(INC_DIR)/parser.h \
		   $(INC_DIR)/token.h \
		   $(INC_DIR)/tokenId.h \
		   $(INC_DIR)/error.h \
		   $(INC_DIR)/tree.h \
		   $(INC_DIR)/alpha_beta.h
OBJECTS = main.o \
		  standard.o \
		  parser.o \
		  token.o \
		  error.o \
		  tree.o \
		  alpha_beta.o

all: $(TARGET)

%.o: $(SRC_DIR)/%.cc $(INCLUDES)
	$(CC) $(PARAMETERS) -c -o $@ $<

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

clean:
	rm -f *.o $(TARGET)

build: $(TARGET)
	
run: build
	./$(TARGET) < positives.txt

debug: build
	valgrind --leak-check=full ./$(TARGET) d $(OUT_FILE) < positives.txt