##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Compilation
##

CC = gcc

CFLAGS = -Wall -Wextra -Iinclude

SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

SRCS = $(wildcard $(SRC_DIR)/*.c)
SRCS += main.c

OBJS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))

TARGET = bsq

RED = \033[0;31m
GREEN = \033[0;32m
NC = \033[0m

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "$(GREEN)compiling the program $(TARGET)$(NC)"
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)$<	[✓]$(NC)"

$(BUILD_DIR)/main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)$<	[✓]$(NC)"

clean:
	@echo "$(RED)Cleaning up object files$(NC)"
	rm -f $(BUILD_DIR)/*.o

fclean: clean
	@echo "$(RED)Cleaning up the executable $(TARGET)$(NC)"
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re