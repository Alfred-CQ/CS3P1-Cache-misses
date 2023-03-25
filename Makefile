# Compile Flags
CC          = g++
LD          = g++
CCFLAGS     = -Wall -Wextra -std=c++17
OPT			= -O0
DEPFLAGS    = -MP -MD

# Folders
SRC_DIR		= ./src
BUILD_DIR	= ./build
BIN_DIR     = ./bin
INCLUDE_DIR	=. ./include

# Programs
PROG	 = main
PROG_VAL = bin_for_valgrind

# CPP, Sources, Dependencies and Object files
CPP_LIST = main.cpp matrix.cpp
SRC_LIST = $(patsubst %.cpp,$(SRC_DIR)/%.cpp,$(CPP_LIST))
OBJ_LIST = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_LIST))
DEP_LIST = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.d,$(SRC_LIST))

CPP_LIST_VAL = analysis_tools.cpp matrix.cpp
SRC_LIST_VAL = $(patsubst %.cpp,$(SRC_DIR)/%.cpp,$(CPP_LIST_VAL))
OBJ_LIST_VAL = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_LIST_VAL))
DEP_LIST_VAL = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.d,$(SRC_LIST_VAL))

INCLUDES = $(foreach dir, $(INCLUDE_DIR), $(addprefix -I, $(dir)))
-include $(DEP_LIST)
-include $(DEP_LIST_VAL)

# Prettier Makefile
NO_COLOR=$(shell printf "%b" "\033[0m")
OK_COLOR=$(shell printf "%b" "\033[32;01m")
OK_STRING=$(OK_COLOR)[OK]$(NO_COLOR)

.PHONY: all clean $(PROG)

all: $(BIN_DIR)/$(PROG)

tool_test: $(BIN_DIR)/$(PROG_VAL)

$(BIN_DIR)/$(PROG): $(OBJ_LIST)
	@echo "Linking the target $(PROG) in $(BIN_DIR)"
	$(LD) -o $@ $^
	@echo ""

$(BIN_DIR)/$(PROG_VAL): $(OBJ_LIST_VAL)
	@echo "Linking the target $(PROG_VAL) in $(BIN_DIR)"
	$(LD) -o $@ $^
	@echo ""

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "Compiling $< in $(BUILD_DIR) $(OK_STRING)"
	@$(CC) $(CCFLAGS) -g $(INCLUDES) $(OPT) $(DEPFLAGS) -c -o $@ $<

clean:
	rm -f $(BIN_DIR)/$(PROG) $(BUILD_DIR)/*.o $(BUILD_DIR)/*.d