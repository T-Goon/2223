CC = g++
CFLAGS = -Wall -Werror -Wextra -O2 -fPIC
LINK =

OBJECT_DIR = obj
INCLUDE =
SRC = $(wildcard *.cpp)

OBJ = $(patsubst %.cpp,$(OBJECT_DIR)/%.o,$(SRC))

ARTIFACT = nqueens
ARTIFACT1 = solver

all: src

$(OBJECT_DIR)/%.o: %.cpp
	$(CC) -c $(INCLUDE) -o $@ $< $(CFLAGS)

$(ARTIFACT): queens.cpp
	$(CC) -o $@ $^ $(LINK)

$(ARTIFACT1): nqueen_solver.cpp
	$(CC) -o $@ $^ $(LINK)

init:
	@mkdir -p $(OBJECT_DIR)

src: init $(ARTIFACT) $(ARTIFACT1)

clean:
	rm -rf $(OBJECT_DIR) $(ARTIFACT) $(ARTIFACT1)
