# LabWork 2
# Шафиков Руслан Альвиртович, group 24.Б83-мм
# st112650@stdudent.spbu.ru

CXX = g++
CXXFLAGS = -Wall -g -Werror -Wpedantic -W


TEST_SRC = main_test.cpp
SRC = main.cpp

TEST_OBJ = $(TEST_SRC:.cpp=.o)
OBJ = $(SRC:.cpp=.o)

GTEST_DIR = /usr/include/gtest
GTEST_LIB = -lgtest -lgtest_main -pthread
EXECUTABLE = main_test main
all: $(TEST_TARGET) $(TARGET)

$(TEST_TARGET): $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -I$(GTEST_DIR) -o $@ $^ $(GTEST_LIB)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I$(GTEST_DIR) -c $<

clean:
	rm -f $(TEST_OBJ) $(OBJ) $(TEST_TARGET) $(TARGET)
