CC = gcc
CFLAGS  = -Wall -I.

SRC_DIR = src
OBJ_DIR = obj




SRCS =  $(SRC_DIR)/roman_to_decimal.c $(SRC_DIR)/check_roman.c
OBJS =  $(OBJ_DIR)/roman_to_decimal.o $(OBJ_DIR)/check_roman.o




all: $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c  $< -o $@

roman_calculator: $(APPS)
	gcc $(CFLAGS) -o $@ $^

check:
	gcc $(OBJ_DIR)/roman_to_decimal.o $(OBJ_DIR)/check_roman.o -lcheck -lm -lpthread -lrt -lgcov -coverage -o check_roman
