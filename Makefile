# Compile Flags
CC          = g++
LD          = g++
CCFLAGS     = -Wall -Wextra -std=c++17
OPT			= -O0
DEPFLAGS    = -MP -MD
THREADS		= -pthread

# Folders
SRC_DIR		= ./src
BUILD_DIR	= ./build
BIN_DIR     = ./bin
INCLUDE_DIR	=. ./include