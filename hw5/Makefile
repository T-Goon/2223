CC = g++
CFLAGS = -Wall -Werror -Wextra -O2 -fPIC
LINK =

OBJECT_DIR = obj
INCLUDE =
SRC = $(wildcard *.cpp)

OBJ = $(patsubst %.cpp,$(OBJECT_DIR)/%.o,$(SRC))

ARTIFACT = hw5
ARTIFACT1 = djikstra

all: src

$(OBJECT_DIR)/%.o: %.cpp
	$(CC) -c $(INCLUDE) -o $@ $< $(CFLAGS)

$(ARTIFACT): hw5.cpp
	$(CC) -o $@ $^ $(LINK)

$(ARTIFACT1): Dijkstra.cpp
	$(CC) -o $@ $^ $(LINK)

init:
	@mkdir -p $(OBJECT_DIR)

src: init $(ARTIFACT) $(ARTIFACT1)

clean:
	rm -rf $(OBJECT_DIR) $(ARTIFACT) $(ARTIFACT1)
