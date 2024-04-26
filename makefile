CXX := g++
CXXFLAGS := -std=c++20
LDFLAGS := -lgtest -lgtest_main

OUT_DIR := ./out
BUILD_DIR := $(OUT_DIR)/bin

TASK1_DIR := ./Equation
TASK1_NAME := Equation

TASK2_DIR := ./Vet
TASK2_NAME := Vet
TASK2_SOURCES := $(wildcard $(TASK2_DIR)/*.cpp)
TASK2_OBJECTS := $(TASK2_SOURCES:$(TASK2_DIR)/%.cpp=$(BUILD_DIR)/%.o)

UNIT_TEST_DIR := ./unit_test
UNIT_TEST_1 := task1_tester
UNIT_TEST_2 := task2_tester

.PHONY: all dirCreation task1 task2 tests clean

all: dirCreation task1 task2 tests
	@echo "Build complete."

dirCreation:
	mkdir -p $(BUILD_DIR)

task1: dirCreation $(BUILD_DIR)/$(TASK1_NAME).o

task2: dirCreation $(TASK2_OBJECTS)

$(BUILD_DIR)/$(TASK1_NAME).o: $(TASK1_DIR)/$(TASK1_NAME).cpp
	$(CXX) $(CXXFLAGS) -c ${(TASK1_DIR)/$(TASK1_NAME).cpp -o $@}
	
$(BUILD_DIR)/%.o: $(TASK2_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c ${(filter-out $(BUILD_DIR)/$(TASK1_NAME).o, $^) -o $@}

tests: task1 task2
	$(CXX) $(CXXFLAGS) $(BUILD_DIR)/$(TASK1_NAME).o $(UNIT_TEST_DIR)/$(UNIT_TEST_1).cpp $(LDFLAGS) -o $(OUT_DIR)/$(UNIT_TEST_1).out
	$(CXX) $(CXXFLAGS) $(TASK2_OBJECTS) $(UNIT_TEST_DIR)/$(UNIT_TEST_2).cpp $(LDFLAGS) -o $(OUT_DIR)/$(UNIT_TEST_2).out

clean:
	rm -rf $(OUT_DIR)

