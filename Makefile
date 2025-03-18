# LabWork 2
# Шафиков Руслан Альвиртович, group 24.Б83-мм
# st112650@stdudent.spbu.ru

CC = clang++
CFLAGS=-Werror -Wpedantic -Wall -std=c++20
LDFLAGS=-lgtest -lgtest_main -lpthread
SOURCE_DIR = srs src/character src/characters/agility_roles src/characters/ancherman_roles src/characters/magic_roles
SRC = $(wildcard $(patsubst %,%/*.cpp,$(SOURCE_DIR))) main.cpp main_test.cpp
OBJ = $(SRC:.cpp=.o)
EXECUTABLE = main_test main


all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(LDFLAGS) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -rf $(EXECUTABLE) $(OBJ) *.mk