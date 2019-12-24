CC = g++
CFLAGS = -Wall -Wextra -O2 -fPIC -std=c++11 -g
LINK = -lrt

OBJECT_DIR = obj
INCLUDE =
SRC = $(wildcard *.cpp)

OBJ = $(patsubst %.cpp,$(OBJECT_DIR)/%.o,$(SRC))

ARTIFACT = hw1

all: src

$(OBJECT_DIR)/%.o: %.cpp
	$(CC) -c $(INCLUDE) -o $@ $< $(CFLAGS)

$(ARTIFACT): $(OBJ)
	$(CC) -o $@ $^ $(LINK)

init:
	@mkdir -p $(OBJECT_DIR)

src: init $(ARTIFACT)

clean:
	rm -rf $(OBJECT_DIR) $(ARTIFACT)
