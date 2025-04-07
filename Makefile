# LabWork 2
# Шафиков Руслан Альвиртович, group 24.Б83-мм
# st112650@stdudent.spbu.ru

CC          := clang++
CFLAGS      := -Werror -Wpedantic -Wall -std=c++20
TEST_LDFLAGS:= -lgtest -lgtest_main -lpthread

SOURCE_DIRS := src src/agility_roles src/ancherman_roles src/magic_roles src/Gameplay src/Team
SOURCES     := $(wildcard $(patsubst %,%/*.cpp,$(SOURCE_DIRS)))

OBJ_DIR     := build/obj
OBJ_MAIN    := $(OBJ_DIR)/main
OBJ_TEST    := $(OBJ_DIR)/test

MAIN_SRCS   := $(filter-out src/main_test.cpp,$(SOURCES))
TEST_SRCS   := $(filter-out src/main.cpp,$(SOURCES)) src/main_test.cpp

MAIN_OBJS   := $(patsubst %.cpp,$(OBJ_MAIN)/%.o,$(MAIN_SRCS))
TEST_OBJS   := $(patsubst %.cpp,$(OBJ_TEST)/%.o,$(TEST_SRCS))

.PHONY: all clean
all: main main_test

main: $(MAIN_OBJS)
	$(CC) $^ $(CFLAGS) -o $@

main_test: $(TEST_OBJS)
	$(CC) $^ $(CFLAGS) $(TEST_LDFLAGS) -o $@

$(OBJ_MAIN)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


$(OBJ_TEST)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# ---------------------------------------------------------
clean:
	rm -rf build main main_test

