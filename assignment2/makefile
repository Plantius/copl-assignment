CC = g++

PARAMETERS = -Wall -Wextra -Wpedantic -g

TARGET = lambda
SRC_DIR = ./src
INC_DIR = ./include

INCLUDES = $(INC_DIR)/standard.h \
		   $(INC_DIR)/parser.h \
		   $(INC_DIR)/token.h \
		   $(INC_DIR)/tokenId.h \
		   $(INC_DIR)/error.h \
		   $(INC_DIR)/alpha_beta.h
OBJECTS = main.o \
		  standard.o \
		  parser.o \
		  token.o \
		  error.o \
		  alpha_beta.o

%.o: $(SRC_DIR)/%.cc $(INCLUDES)
	$(CC) $(PARAMETERS) -c -o $@ $<

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

clean:
	rm -f *.o $(TARGET)

build: $(TARGET)
	
run: build
	$(TARGET) ./positives.txt