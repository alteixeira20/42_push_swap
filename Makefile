# **************************************************************************** #
#                                  CONFIGURATION                               #
# **************************************************************************** #

# Compiler and Flags
CC       		:= cc
CFLAGS   		:= -Wall -Wextra -Werror -g
VFLAGS   		:= --leak-check=full --show-leak-kinds=all --track-origins=yes

# Directories
SRC_DIR  := src
LST_DIR  := $(SRC_DIR)/utils/lst
OPS_DIR  := $(SRC_DIR)/utils/ops/
PARSE_DIR := $(SRC_DIR)/utils/parsing
SORT_DIR := $(SRC_DIR)/utils/sorting
OBJ_DIR  := obj
OBJ_CHECKER_DIR := obj_checker
RESULTS_DIR := results

# Libft
LIBFT_REPO := https://github.com/alteixeira20/42_libft.git
LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

# Test Cases
TEST_VALID := test_valid.txt

# Source Files
SRC  := $(SRC_DIR)/push_swap.c \
        $(LST_DIR)/ft_lst_new_ps.c $(LST_DIR)/ft_lst_clear_ps.c \
        $(LST_DIR)/ft_lst_addtop_ps.c $(LST_DIR)/ft_lst_addbottom_ps.c \
        $(LST_DIR)/ft_lst_size_ps.c $(LST_DIR)/ft_lst_last_ps.c \
        $(LST_DIR)/ft_lst_assignindex_ps.c $(LST_DIR)/ft_lst_findindex_ps.c \
        $(LST_DIR)/ft_lst_max_ps.c $(LST_DIR)/ft_lst_min_ps.c \
		$(OPS_DIR)/push.c $(OPS_DIR)/swap.c \
        $(OPS_DIR)/rotate.c $(OPS_DIR)/reverserotate.c \
        $(PARSE_DIR)/parsing.c $(PARSE_DIR)/parsing_utils.c $(PARSE_DIR)/parsing_errors.c \
        $(SORT_DIR)/sort_small.c $(SORT_DIR)/sort_large.c $(SORT_DIR)/sorting_utils.c

SRC_CHECKER  := $(SRC_DIR)/checker.c \
        $(LST_DIR)/ft_lst_new_ps.c $(LST_DIR)/ft_lst_clear_ps.c \
        $(LST_DIR)/ft_lst_addtop_ps.c $(LST_DIR)/ft_lst_addbottom_ps.c \
        $(LST_DIR)/ft_lst_size_ps.c $(LST_DIR)/ft_lst_last_ps.c \
        $(LST_DIR)/ft_lst_assignindex_ps.c $(LST_DIR)/ft_lst_findindex_ps.c \
        $(LST_DIR)/ft_lst_max_ps.c $(LST_DIR)/ft_lst_min_ps.c \
        $(OPS_DIR)/push.c $(OPS_DIR)/swap.c \
        $(OPS_DIR)/rotate.c $(OPS_DIR)/reverserotate.c \
        $(PARSE_DIR)/parsing.c $(PARSE_DIR)/parsing_utils.c $(PARSE_DIR)/parsing_errors.c \
        $(SORT_DIR)/sort_small.c $(SORT_DIR)/sort_large.c $(SORT_DIR)/sorting_utils.c

OBJ			:= $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(SRC)))
OBJ_CHECKER := $(patsubst $(SRC_DIR)/%.c, $(OBJ_CHECKER_DIR)/%.o, $(SRC_CHECKER))

# Executable
MAIN				:= push_swap
ORIGINAL_CHECKER	:= ./checker_linux
CUSTOM_CHECKER		:= checker
TESTER				:= tester
SHELL				:= /bin/bash

# Test Files
TEST_VALID 			:= test_valid.txt
TEST_ERROR			:= test_error.txt

# Colors
BOLD 	:= $(shell tput bold)
GREEN	:= $(shell tput setaf 2)
RED  	:= $(shell tput setaf 1)
YELLOW	:= $(shell tput setaf 3)
RESET	:= $(shell tput sgr0)
GREY	:= $(shell tput setaf 8)
ORANGE	:= $(shell tput setaf 214)

# **************************************************************************** #
#                                  TARGETS                                     #
# **************************************************************************** #

# Default Rule - Compile push_swap
all: $(LIBFT) $(MAIN) tester

$(LIBFT):
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		echo "$(YELLOW)📥 Cloning Libft...$(RESET)"; \
		git clone $(LIBFT_REPO) $(LIBFT_DIR); \
	fi
	@$(MAKE) -C $(LIBFT_DIR)


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

$(OBJ_CHECKER_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(MAIN): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(MAIN)
	@echo "$(BOLD)✅ push_swap Compiled Successfully!$(RESET)"

$(CUSTOM_CHECKER): $(LIBFT) $(OBJ_CHECKER)
	@$(CC) $(CFLAGS) $(OBJ_CHECKER) $(LIBFT) -o $(CUSTOM_CHECKER)
	@echo "$(BOLD)✅ Checker Compiled Successfully!$(RESET)"

$(TESTER): $(LIBFT) $(OBJ_CHECKER_DIR)/tester.o $(filter-out $(OBJ_CHECKER_DIR)/checker.o, $(OBJ_CHECKER))
	@$(CC) $(CFLAGS) $(OBJ_CHECKER_DIR)/tester.o $(filter-out $(OBJ_CHECKER_DIR)/checker.o, $(OBJ_CHECKER)) $(LIBFT) -o $(TESTER)
	@echo "$(BOLD)✅ Tester Compiled Successfully!$(RESET)"

# **************************************************************************** #
#                              TESTING AUTOMATION                             #
# **************************************************************************** #

# Run tests using different argument sizes
test: $(MAIN) test_error

# Define test cases and output results
test_cases:
	@if [ ! -s $(TEST_FILE) ]; then \
		echo "$(RED)❌ Error: test_valid.txt is empty or missing!$(RESET)"; \
		exit 1; \
	fi
	@echo "$(BOLD)-----------------------------------$(RESET)"
	@echo "$(BOLD)🔍 Running Tests on push_swap$(RESET)"
	@echo "$(BOLD)-----------------------------------$(RESET)"
	@count=1; \
	while IFS= read -r args; do \
		if [ -z "$$args" ]; then continue; fi; \
		echo "$(ORANGE)Test $$count:$(RESET)"; \
		echo "$(GREY) Initial Stack: $$args"; \
		# Capture push_swap output and count moves \
		output=$$(./$(MAIN) $$args); \
		moves=$$(echo "$$output" | wc -l); \
		# Compute expected sorted stack \
		expected_sorted=$$(echo "$$args" | tr ' ' '\n' | sort -n | tr '\n' ' '); \
		# Capture final stack after applying moves \
		final_stack=$$(echo "$$output" | ./$(TESTER) $$args | tail -n 1); \
		echo "$(GREY) Expected Stack: $$expected_sorted"; \
		# Sorting validation \
		if [ "$$output" = "" ]; then \
			final_result="OK"; \
		else \
			final_result=$$(echo "$$output" | $(ORIGINAL_CHECKER) $$args); \
		fi; \
		if [ "$$final_result" = "OK" ]; then \
			echo "$(GREEN)	✅ Sorted Successfully in $$moves moves$(RESET)"; \
		else \
			echo "$(RED)	Sorting Failed:$(RESET)"; \
			echo "$(RED)	⛔ Final Stack: $$final_stack$(RESET)"; \
			# Check if stack matches expected \
			if [ "$$expected_sorted" != "$$final_stack" ]; then \
				echo "$(RED)	⛔ Stack not in correct order!$(RESET)"; \
			fi; \
			# Check for duplicate numbers \
			dups=$$(echo "$$args" | tr ' ' '\n' | sort | uniq -d | tr '\n' ' '); \
			if [ ! -z "$$dups" ]; then \
				echo "$(RED)	⛔ Duplicate numbers found: $$dups$(RESET)"; \
			fi; \
			# Check for missing numbers \
			missing=$$(comm -23 <(echo "$$args" | tr ' ' '\n' | sort) <(echo "$$final_stack" | tr ' ' '\n' | sort) | tr '\n' ' '); \
			if [ ! -z "$$missing" ]; then \
				echo "$(RED)	⛔ Missing numbers in final stack: $$missing$(RESET)"; \
			fi; \
		fi; \
		# Run Valgrind \
		valgrind_output=$$(valgrind $(VFLAGS) ./$(MAIN) $$args 2>&1 | grep "definitely lost:" | awk '{print $$4}'); \
		if [ -z "$$valgrind_output" ] || [ "$$valgrind_output" = "0" ]; then \
			echo "$(GREEN)	✅ Passed on Valgrind$(RESET)"; \
		else \
			echo "$(RED)	❌ Valgrind Errors Found$(RESET)"; \
		fi; \
		count=$$((count+1)); \
	done < $(TEST_VALID)

test_error:
	@mkdir -p $(RESULTS_DIR)
	@$(MAKE) --no-print-directory test_cases | tee $(RESULTS_DIR)/test_results.txt
	@echo "$(BOLD)-----------------------------------$(RESET)"
	@echo "$(BOLD)🔄 Running Error Input Tests...$(RESET)"
	@echo "$(BOLD)-----------------------------------$(RESET)"
	@if [ ! -s test_error.txt ]; then \
		echo "$(RED)❌ Error: test_error.txt is missing or empty!$(RESET)"; \
		exit 1; \
	fi
	@while IFS= read -r args; do \
		if [ -z "$$args" ]; then continue; fi; \
		echo "$(ORANGE)Error Case:$(RESET) $$args"; \
		output=$$(./$(MAIN) $$args 2>&1); \
		if echo "$$output" | grep -q "Error"; then \
			echo "$(GREEN)	✅ Error detected as expected$(RESET)"; \
		else \
			echo "$(RED)	❌ ERROR TEST FAILED$(RESET)"; \
		fi; \
	done < $(TEST_ERROR)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ_CHECKER_DIR)
	@rm -f $(MAIN)
	@rm -f $(CUSTOM_CHECKER)
	@rm -f $(TESTER)
	@echo "$(YELLOW)🗑 Cleaned Object directories and Executables.$(RESET)"

fclean: clean
	@rm -rf $(RESULTS_DIR)
	@rm -rf $(LIBFT_DIR)
	@echo "$(YELLOW)🗑 Cleaned up Libft and Results directory.$(RESET)"

re: fclean all
