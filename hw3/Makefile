CC = g++
CFLAGS = -Wall -Wextra -O2 -fPIC
LINK =

OBJECT_DIR = obj
INCLUDE =
SRC = $(wildcard *.cpp)

OBJ = $(patsubst %.cpp,$(OBJECT_DIR)/%.o,$(SRC))

ARTIFACT = palindromecheck
ARTIFACT1 = easyinversioncount
ARTIFACT2 = fastinversioncount
ARTIFACT3 = graycodesarefun

all: src

$(OBJECT_DIR)/%.o: %.cpp
	$(CC) -c $(INCLUDE) -o $@ $< $(CFLAGS)

$(ARTIFACT): $(ARTIFACT).cpp
	$(CC) -o $@ $^ $(LINK)

$(ARTIFACT1): $(ARTIFACT1).cpp
	$(CC) -o $@ $^ $(LINK)

$(ARTIFACT2): $(ARTIFACT2).cpp
	$(CC) -o $@ $^ $(LINK)

$(ARTIFACT3): $(ARTIFACT3).cpp
	$(CC) -o $@ $^ $(LINK)

init:
	@mkdir -p $(OBJECT_DIR)

src: init $(ARTIFACT) $(ARTIFACT1) $(ARTIFACT2) $(ARTIFACT3)

clean:
	rm -rf $(OBJECT_DIR) $(ARTIFACT) $(ARTIFACT1) $(ARTIFACT2) $(ARTIFACT3)
