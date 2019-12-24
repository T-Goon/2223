CC = g++
CFLAGS = -Wall -Wextra -O2 -fPIC
LINK =

OBJECT_DIR = obj
INCLUDE =
SRC = $(wildcard *.cpp)

OBJ = $(patsubst %.cpp,$(OBJECT_DIR)/%.o,$(SRC))

ARTIFACT = gauss_jordan
ARTIFACT1 = knapsack

all: src

$(OBJECT_DIR)/%.o: %.cpp
	$(CC) -c $(INCLUDE) -o $@ $< $(CFLAGS)

$(ARTIFACT): gauss_jordan.o
	$(CC) -o $@ $^ $(LINK)

$(ARTIFACT1): hw4.o
	$(CC) -o $@ $^ $(LINK)

init:
	@mkdir -p $(OBJECT_DIR)

src: init $(ARTIFACT) $(ARTIFACT1)

clean:
	rm -rf $(OBJECT_DIR) *.o $(ARTIFACT) $(ARTIFACT1)
