CC = gcc
CFLAGS  = -Wall -I.
INC_DIR = include
SRC_DIR = src
OBJ_DIR = obj




SRCS = $(SRC_DIR)/roman_to_decimal.c $(SRC_DIR)/decimal_to_roman.c $(SRC_DIR)/roman_calculator.c $(SRC_DIR)/roman_calculator_application.c $(SRC_DIR)/check_roman.c
OBJS = $(OBJ_DIR)/roman_to_decimal.o $(OBJ_DIR)/decimal_to_roman.o $(OBJ_DIR)/roman_calculator.o $(OBJ_DIR)/roman_calculator_application.o $(OBJ_DIR)/check_roman.o

APPS =$(OBJ_DIR)/roman_to_decimal.o $(OBJ_DIR)/decimal_to_roman.o $(OBJ_DIR)/roman_calculator.o $(OBJ_DIR)/roman_calculator_application.o

TSTS = $(OBJ_DIR)/roman_to_decimal.o $(OBJ_DIR)/decimal_to_roman.o $(OBJ_DIR)/roman_calculator.o $(OBJ_DIR)/check_roman.o

DEPS = $(INC_DIR)/roman_to_decimal.h $(INC_DIR)/decimal_to_roman.h $(INC_DIR)/roman_calculator.h


all: $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c  $< -o $@

roman_calculator: $(APPS)
	gcc $(CFLAGS) -o $@ $^

check:
	gcc $(OBJ_DIR)/roman_to_decimal.o $(OBJ_DIR)/decimal_to_roman.o $(OBJ_DIR)/roman_calculator.o $(OBJ_DIR)/check_roman.o -lcheck -lm -lpthread -lrt -lgcov -coverage -o check_roman
