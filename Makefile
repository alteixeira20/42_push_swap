# **************************************************************************** #
#                                  CONFIGURATION                               #
# **************************************************************************** #

# Compiler and Flags
CC       := cc
CFLAGS   := -Wall -Wextra -Werror -g
VFLAGS   := --leak-check=full --show-leak-kinds=all --track-origins=yes
CHECKER  := ./checker_linux

# Directories
SRC_DIR  := src
LST_DIR  := $(SRC_DIR)/utils/lst
OPS_DIR  := $(SRC_DIR)/ops/
PARSE_DIR := $(SRC_DIR)/utils/parsing
SORT_DIR := $(SRC_DIR)/sorting
OBJ_DIR  := obj
RESULTS_DIR := results
LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a
TEST_FILE := test_examples.txt

# Source Files
SRC  := $(SRC_DIR)/main.c \
        $(LST_DIR)/ft_lstnew_ps.c \
        $(LST_DIR)/ft_lstadd_front_ps.c \
        $(LST_DIR)/ft_lstadd_back_ps.c \
        $(LST_DIR)/ft_lstsize_ps.c \
        $(LST_DIR)/ft_lstlast_ps.c \
        $(LST_DIR)/ft_lstclear_ps.c \
        $(LST_DIR)/ft_lstindex_ps.c \
        $(OPS_DIR)/push.c $(OPS_DIR)/swap.c \
        $(OPS_DIR)/rotate.c $(OPS_DIR)/reverserotate.c \
        $(PARSE_DIR)/parsing.c $(PARSE_DIR)/parsing_utils.c $(PARSE_DIR)/parsing_errors.c \
        $(SORT_DIR)/sort_small.c $(SORT_DIR)/sorting_utils.c

OBJ := $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRC)))

# Executable
NAME := push_swap
SHELL := /bin/bash

# Colors
BOLD  := $(shell tput bold)
GREEN := $(shell tput setaf 2)
RED   := $(shell tput setaf 1)
YELLOW := $(shell tput setaf 3)
RESET := $(shell tput sgr0)

# **************************************************************************** #
#                                  TARGETS                                     #
# **************************************************************************** #

# Default Rule - Compile push_swap
all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(LST_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(OPS_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(PARSE_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SORT_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(BOLD)✅ push_swap Compiled Successfully!$(RESET)"

# **************************************************************************** #
#                              TESTING AUTOMATION                             #
# **************************************************************************** #

# Run tests using different argument sizes
test: $(NAME)
	@mkdir -p $(RESULTS_DIR)
	@echo "$(BOLD)🔍 Running Tests on push_swap$(RESET)"
	@$(MAKE) test_cases | tee $(RESULTS_DIR)/test_results.txt

# Define test cases and output results
test_cases:
	@if [ ! -s $(TEST_FILE) ]; then \
		echo "$(RED)❌ Error: test_examples.txt is empty or missing!$(RESET)"; \
		exit 1; \
	fi
	@count=1; \
	while IFS= read -r args; do \
		if [ -z "$$args" ]; then continue; fi; \
		echo "$(YELLOW)-----------------------------------$(RESET)"; \
		echo "$(BOLD)Test $$count:$(RESET)"; \
		echo "$(YELLOW)Initial Stack: $(RESET)$$args"; \
		# Run push_swap and store output \
		moves=$$(./$(NAME) $$args | tee $(RESULTS_DIR)/test_moves.txt | wc -l); \
		# Run checker and capture result \
		output=$$(./$(NAME) $$args); \
		if [ -z "$$output" ]; then \
    		final_result="OK"; \
		else \
    		final_result=$$(echo "$$output" | $(CHECKER) $$args); \
		fi; \
		# Compute the correct sorted stack \
		expected_sorted=$$(echo "$$args" | tr ' ' '\n' | sort -n | tr '\n' ' '); \
		echo "$(YELLOW)Expected Stack: $(RESET)$$expected_sorted"; \
		# Sorting validation \
		if [ "$$final_result" = "OK" ]; then \
			echo "$(GREEN)✅ Sorted Successfully in $$moves moves$(RESET)"; \
		else \
			echo "$(RED)❌ Sorting Failed$(RESET)"; \
			echo "$(RED)🔍 Debug Info:$(RESET)"; \
			# Compare expected vs actual sorted stack \
			actual_sorted=$$(./$(NAME) $$args | awk '{print}' | tr '\n' ' '); \
			if [ "$$expected_sorted" != "$$actual_sorted" ]; then \
				echo "$(RED)⛔ Stack not in correct order!$(RESET)"; \
			fi; \
			# Check for duplicate numbers \
			dups=$$(echo "$$args" | tr ' ' '\n' | sort | uniq -d | tr '\n' ' '); \
			if [ ! -z "$$dups" ]; then \
				echo "$(RED)⛔ Duplicate numbers found: $$dups$(RESET)"; \
			fi; \
			# Check if missing numbers \
			missing=$$(comm -23 <(echo "$$args" | tr ' ' '\n' | sort) <(echo "$$actual_sorted" | tr ' ' '\n' | sort)); \
			if [ ! -z "$$missing" ]; then \
				echo "$(RED)⛔ Missing numbers in final stack: $$missing$(RESET)"; \
			fi; \
		fi; \
		# Run Valgrind \
		valgrind_output=$$(valgrind $(VFLAGS) ./$(NAME) $$args 2>&1 | grep "definitely lost:" | awk '{print $$4}'); \
		if [ -z "$$valgrind_output" ] || [ "$$valgrind_output" = "0" ]; then \
			echo "$(GREEN)✅ Passed on Valgrind$(RESET)"; \
		else \
			echo "$(RED)❌ Valgrind Errors Found$(RESET)"; \
		fi; \
		count=$$((count+1)); \
	done < $(TEST_FILE)

# Clean object files and binaries
fclean:
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@rm -rf $(RESULTS_DIR)
	@echo "$(YELLOW)🗑 Cleaned up build files.$(RESET)"

re: fclean all

