CC = g++
CFLAGS = -Wall -Werror -Wextra -Ofast -fPIC
LINK =

OBJECT_DIR = obj
INCLUDE =
SRC = $(wildcard *.cpp)

ARTIFACT1 = lucas
ARTIFACT2 = suribach

all: src

$(OBJECT_DIR)/%.o: %.cpp
	$(CC) -c $(INCLUDE) -o $@ $< $(CFLAGS)

$(ARTIFACT1): lucas.o
	$(CC) -o $@ $^ $(LINK)

$(ARTIFACT2): suribach.o
	$(CC) -o $@ $^ $(LINK)


src: $(ARTIFACT1) $(ARTIFACT2)

clean:
	rm -rf *.o $(ARTIFACT1) $(ARTIFACT2)
