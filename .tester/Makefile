# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/05 17:14:23 by paalexan          #+#    #+#              #
#    Updated: 2025/02/08 12:44:01 by paalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# **************************************************************************** #
#                                  CONFIGURATION                               #
# **************************************************************************** #

# Compiler and Flags
CC       := cc
CFLAGS   := -Wall -Wextra -Werror -g
VFLAGS   := --leak-check=full --show-leak-kinds=all --track-origins=yes

# Directories
SRC_DIR  := ../src
LST_DIR  := $(SRC_DIR)/utils/lst
OPS_DIR  := $(SRC_DIR)/ops/
PARSE_DIR := $(SRC_DIR)/utils/parsing
OBJ_DIR  := obj
MAIN_DIR := mains
RESULTS_DIR := results
LIBFT_DIR := ../libft
LIBFT := $(LIBFT_DIR)/libft.a

# Source Files
LST_SRC  := $(LST_DIR)/ft_lstnew_ps.c \
            $(LST_DIR)/ft_lstadd_front_ps.c \
            $(LST_DIR)/ft_lstadd_back_ps.c \
            $(LST_DIR)/ft_lstsize_ps.c \
            $(LST_DIR)/ft_lstlast_ps.c \
            $(LST_DIR)/ft_lstclear_ps.c \
            $(LST_DIR)/ft_lstindex_ps.c

OPS_SRC  := $(OPS_DIR)/push.c $(OPS_DIR)/swap.c \
            $(OPS_DIR)/rotate.c $(OPS_DIR)/reverserotate.c

PARSE_SRC := $(PARSE_DIR)/parsing.c \
             $(PARSE_DIR)/parsing_utils.c \
             $(PARSE_DIR)/parsing_errors.c

# Object Files
LST_OBJ := $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(LST_SRC)))
OPS_OBJ := $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(OPS_SRC)))
PARSE_OBJ := $(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir $(PARSE_SRC)))

# Test Executables
LST_TEST := $(MAIN_DIR)/lst_test.c
OPS_TEST := $(MAIN_DIR)/ops_test.c
PARSE_TEST := $(MAIN_DIR)/parsing_test.c

# Colors
BOLD  := $(shell tput bold)
RED   := $(shell tput setaf 1)
GREEN := $(shell tput setaf 2)
YELLOW := $(shell tput setaf 3)
BLUE  := $(shell tput setaf 4)
GREY  := $(shell tput setaf 7)
RESET := $(shell tput sgr0)

# **************************************************************************** #
#                                  TARGETS                                     #
# **************************************************************************** #

# Default Rule
all: valgrind_lst valgrind_ops valgrind_parsing

# Build Object Files
$(OBJ_DIR)/%.o: $(LST_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(OPS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(PARSE_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Test Stack Operations Functions
test_ops: $(OPS_OBJ)
	@mkdir -p $(RESULTS_DIR)
	@$(CC) $(CFLAGS) $(OPS_OBJ) $(LST_OBJ) $(OPS_TEST) $(LIBFT) -o $(RESULTS_DIR)/test_ops.out
	@echo "$(BOLD)🔍 Testing Stack Operations (Push & Swap):$(RESET)"
	@$(RESULTS_DIR)/test_ops.out > $(RESULTS_DIR)/test_ops.txt
	@while read -r line; do \
		if echo "$$line" | grep -q ":"; then \
			fn_name=$$(echo $$line | cut -d':' -f1); \
			logic=$$(echo $$line | cut -d' ' -f3); \
			if [ "$$logic" = "[OK]" ]; then \
				logic_status="$(GREEN)[OK]$(RESET)"; \
			else \
				logic_status="$(RED)[KO]$(RESET)"; \
			fi; \
			echo "$(YELLOW) - $$fn_name:$(RESET) $$logic_status"; \
		fi; \
	done < $(RESULTS_DIR)/test_ops.txt

# Test Linked List Functions
test_lst: $(LST_OBJ)
	@mkdir -p $(RESULTS_DIR)
	@$(CC) $(CFLAGS) $(LST_OBJ) $(LST_TEST) -o $(RESULTS_DIR)/test_lst.out
	@echo "$(YELLOW)-----------------------------------$(RESET)"
	@echo "$(BOLD)🔍 Testing List functions's logic:$(RESET)"
	@$(RESULTS_DIR)/test_lst.out > $(RESULTS_DIR)/test_lst.txt
	@while read -r line; do \
		fn_name=$$(echo $$line | cut -d':' -f1); \
		logic=$$(echo $$line | cut -d' ' -f3); \
		if [ "$$logic" = "[OK]" ]; then \
			logic_status="$(GREEN)[OK]$(RESET)"; \
		else \
			logic_status="$(RED)[KO]$(RESET)"; \
		fi; \
		echo "$(YELLOW) - $$fn_name:$(RESET) $$logic_status"; \
	done < $(RESULTS_DIR)/test_lst.txt

# Test Parsing Functions
test_parsing: $(PARSE_OBJ) $(LST_OBJ)
	@mkdir -p $(RESULTS_DIR)
	@$(CC) $(CFLAGS) $(PARSE_OBJ) $(LST_OBJ) $(PARSE_TEST) -o $(RESULTS_DIR)/test_parsing.out $(LIBFT)
	@echo "$(BOLD)🔍 Testing Parsing Functions:$(RESET)"
	@$(RESULTS_DIR)/test_parsing.out > $(RESULTS_DIR)/test_parsing.txt
	@while read -r line; do \
		fn_name=$$(echo $$line | cut -d':' -f1); \
		logic=$$(echo $$line | awk -F': ' '{print $$2}'); \
		if [ "$$logic" = "[OK]" ]; then \
			logic_status="$(GREEN)[OK]$(RESET)"; \
		else \
			logic_status="$(RED)[KO]$(RESET)"; \
		fi; \
		echo "$(YELLOW) - $$fn_name:$(RESET) $$logic_status"; \
	done < $(RESULTS_DIR)/test_parsing.txt

# Valgrind Memory Leak Check for Parsing
valgrind_parsing: test_parsing
	@echo "$(BOLD)🔍 Running Valgrind for Parsing...$(RESET)"
	@valgrind $(VFLAGS) $(RESULTS_DIR)/test_parsing.out > $(RESULTS_DIR)/valgrind_parsing.txt 2>&1
	@valgrind_output=$$(grep "definitely lost:" $(RESULTS_DIR)/valgrind_parsing.txt | awk '{print $$4}'); \
	if [ -z "$$valgrind_output" ]; then \
		valgrind_output="0"; \
	fi; \
	if [ "$$valgrind_output" = "0" ]; then \
		valgrind_status="$(GREEN)PASSED$(RESET)"; \
	else \
		valgrind_status="$(RED)KO$(RESET) | (Lost: $$valgrind_output bytes)"; \
	fi; \
	echo "$(YELLOW) - Valgrind Test:$(RESET) $$valgrind_status"
	@echo "$(YELLOW)-----------------------------------$(RESET)"

# Valgrind Memory Leak Check
valgrind_ops: test_ops
	@echo "$(BOLD)🔍 Running Valgrind for Stack Operations...$(RESET)"
	@valgrind $(VFLAGS) $(RESULTS_DIR)/test_ops.out > $(RESULTS_DIR)/valgrind_ops.txt 2>&1
	@valgrind_output=$$(grep "definitely lost:" $(RESULTS_DIR)/valgrind_ops.txt | awk '{print $$4}'); \
	if [ -z "$$valgrind_output" ]; then \
		valgrind_output="0"; \
	fi; \
	if [ "$$valgrind_output" = "0" ]; then \
		valgrind_status="$(GREEN)PASSED$(RESET)"; \
	else \
		valgrind_status="$(RED)KO$(RESET) | (Lost: $$valgrind_output bytes)"; \
	fi; \
	echo "$(YELLOW) - Valgrind Test:$(RESET) $$valgrind_status"
	@echo "$(YELLOW)-----------------------------------$(RESET)"

valgrind_lst: test_lst
	@echo "$(BOLD)🔍 Running Valgrind for List Functions...$(RESET)"
	@valgrind $(VFLAGS) $(RESULTS_DIR)/test_lst.out > $(RESULTS_DIR)/valgrind_lst.txt 2>&1
	@valgrind_output=$$(grep "definitely lost:" $(RESULTS_DIR)/valgrind_lst.txt | awk '{print $$4}'); \
	if [ -z "$$valgrind_output" ]; then \
		valgrind_output="0"; \
	fi; \
	if [ "$$valgrind_output" = "0" ]; then \
		valgrind_status="$(GREEN)PASSED$(RESET)"; \
	else \
		valgrind_status="$(RED)KO$(RESET) | (Lost: $$valgrind_output bytes)"; \
	fi; \
	echo "$(YELLOW) - Valgrind Test:$(RESET) $$valgrind_status"
	@echo "$(YELLOW)-----------------------------------$(RESET)"

# Clean Up
clean:
	@rm -rf $(OBJ_DIR)
	@rm -f $(RESULTS_DIR)/test_ops.out $(RESULTS_DIR)/test_lst.out
	@echo "$(YELLOW)🗑 Cleaned up object files and test executables.$(RESET)"

fclean: clean
	@rm -rf $(RESULTS_DIR)
	@echo "$(RED)🗑 Fully cleaned results and binaries.$(RESET)"

re: fclean all
