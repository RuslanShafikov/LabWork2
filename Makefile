# LabWork 2
# Шафиков Руслан Альвиртович, group 24.Б83-мм
# st112650@stdudent.spbu.ru

CC = clang++
CFLAGS = -Werror -Wpedantic -Wall -std=c++20
TEST_LDFLAGS = -lgtest -lgtest_main -lpthread

SOURCE_DIR = src src/agility_roles src/ancherman_roles src/magic_roles src/Gameplay src/Team
SOURCES = $(wildcard $(patsubst %,%/*.cpp,$(SOURCE_DIR)))

# Objects for main program
MAIN_SOURCES = $(SOURCES) main.cpp
MAIN_OBJECTS = $(MAIN_SOURCES:.cpp=.o)

# Objects for test program
TEST_SOURCES = $(SOURCES) main_test.cpp
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)

all: main main_test
main: $(MAIN_OBJECTS)
	$(CC) $(MAIN_OBJECTS) $(CFLAGS) -o $@

main_test: $(TEST_OBJECTS)
	$(CC) $(TEST_OBJECTS) $(CFLAGS) $(TEST_LDFLAGS) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean all
clean:
	rm -rf main main_test $(MAIN_OBJECTS) $(TEST_OBJECTS) *.mk

#run:
#	./main

