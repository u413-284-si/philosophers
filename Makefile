# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/28 13:03:05 by gwolf             #+#    #+#              #
#    Updated: 2023/09/09 12:49:53 by sqiu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ******************************
# *     Text effects           *
# ******************************

RESET := \033[0m
BOLD := \033[1m
BLACK := \033[30m
GREEN := \033[32m
YELLOW := \033[33m
RED := \033[31m
BLUE := \033[34m

# ******************************
# *     Directories            *
# ******************************

SRC_DIR := src
OBJ_DIR := obj
INC_DIR := inc
DEP_DIR := $(OBJ_DIR)/dep
TEST_DIR := test_dir

# ******************************
# *     Libraries              *
# ******************************

LDFLAGS :=
LDLIBS :=

# ******************************
# *     Vars for compiling     *
# ******************************

CC := cc
CPPFLAGS := -I $(INC_DIR)
CFLAGS = -Wall -Werror -Wextra -g -pthread
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.Td
COMPILE = $(CC) $(DEPFLAGS) $(CPPFLAGS) $(CFLAGS) -c
POSTCOMPILE = @mv -f $(DEP_DIR)/$*.Td $(DEP_DIR)/$*.d && touch $@

# ******************************
# *     Targets                *
# ******************************

NAME := philo
TEST := test

# ******************************
# *     Source files           *
# ******************************

SRC :=	mod_cleanup.c\
		mod_err_handling.c\
		mod_feast.c\
		mod_input_check.c\
		mod_mutex_init.c\
		mod_philo_routine.c\
		mod_setup.c\
		mod_utils.c
SRCS := $(addprefix $(SRC_DIR)/, $(SRC))

# ******************************
# *     Object files           *
# ******************************

OBJ := $(SRC:.c=.o)
OBJS := $(addprefix $(OBJ_DIR)/, $(OBJ))
OBJ_MAIN = $(OBJ_DIR)/main.o

# ******************************
# *     Dependency files       *
# ******************************

DEPFILES = $(SRC:%.c=$(DEP_DIR)/%.d)
# add dependency for main, since not in SRC
DEPFILES += $(DEP_DIR)/main.d

# ******************************
# *     Test files             *
# ******************************

TEST_SRC := test_input.c
TEST_SRCS := $(addprefix $(TEST_DIR)/, $(TEST_SRC))
TEST_OBJ := $(TEST_SRC:.c=.o)
TEST_OBJS := $(addprefix $(TEST_DIR)/, $(TEST_OBJ))
TEST_OBJ_MAIN = $(TEST_DIR)/test_main.o

##################################################################################################################################
##################################################################################################################################

# ******************************
# *     Primary target         *
# ******************************

.PHONY: all
all: $(NAME)

# ******************************
# *     NAME linkage           *
# ******************************

# Linking the NAME target
$(NAME): $(LIBFT) $(OBJS) $(OBJ_MAIN)
	@printf "\n$(YELLOW)$(BOLD)link binary$(RESET) [$(BLUE)philo$(RESET)]\n"
	$(CC) $(LDFLAGS) $(OBJS) $(OBJ_MAIN) $(LDLIBS) -o $@
	@printf "\n$(YELLOW)$(BOLD)compilation successful$(RESET) [$(BLUE)philo$(RESET)]\n"
	@printf "$(BOLD)$(GREEN)$@ created!$(RESET)\n\n"

# This target adds fsanitize leak checker to the flags. It needs to clean and recompile.
.PHONY: leak
leak: CFLAGS += -fsanitize=leak
leak: LDFLAGS += -fsanitize=leak
leak: clean $(NAME)
	@printf "Compiled with $(YELLOW)$(BOLD)fsanitize=leak$(RESET)\n\n"

# This target adds fsanitize address checker to the flags. It needs to clean and recompile.
.PHONY: address
address: CFLAGS += -fsanitize=address
address: LDFLAGS += -fsanitize=address
address: clean $(NAME)
	@printf "Compiled with $(YELLOW)$(BOLD)fsanitize=address$(RESET)\n\n"

# This target adds fsanitize thread checker to the flags. It needs to clean and recompile.
.PHONY: thread
thread: CFLAGS += -fsanitize=thread
thread: LDFLAGS += -fsanitize=thread
thread: clean $(NAME)
	@printf "DEBUG: Compiled with $(YELLOW)$(BOLD)fsanitize=thread$(RESET)\n\n"

# Perform memory check on NAME. Needs manual clean if target leak or address was called before
.PHONY: valgr
valgr: $(NAME)
	@valgrind --leak-check=full\
			--show-leak-kinds=all\
			--trace-children=no\
			--track-fds=no\
			./$(NAME)
#			--log-file=valgrind-out.txt\
#	@less ./valgrind-out.txt

# ******************************
# *     TEST linkage           *
# ******************************

# Create the binary TEST, which has its own test_main.
.PHONY: test
$(TEST): CFLAGS = -g
$(TEST): $(OBJS) $(TEST_OBJS) $(TEST_OBJ_MAIN)
	@printf "\n$(YELLOW)$(BOLD)link test binary$(RESET) [$(BLUE)philo$(RESET)]\n"
	$(CC) $(LDFLAGS) $(OBJS) $(TEST_OBJS) $(TEST_OBJ_MAIN) $(LDLIBS) -o $@
	@printf "\n$(YELLOW)$(BOLD)compilation successful$(RESET) [$(BLUE)philo$(RESET)]\n"
	@printf "$(BOLD)$(GREEN)$@ created!$(RESET)\n\n"

# This target adds fsanitize leak checker to the flags. It needs to clean and recompile.
.PHONY: tleak
tleak: CFLAGS += -fsanitize=leak
tleak: LDFLAGS += -fsanitize=leak
tleak: clean tclean $(TEST)
	@printf "Compiled with $(YELLOW)$(BOLD)fsanitize=leak$(RESET)\n\n"

# This target adds fsanitize address checker to the flags. It needs to clean and recompile.
.PHONY: taddress
taddress: CFLAGS += -fsanitize=address
taddress: LDFLAGS += -fsanitize=address
taddress: clean tclean $(TEST)
	@printf "Compiled with $(YELLOW)$(BOLD)fsanitize=address$(RESET)\n\n"

# Perform memory check on TEST. Needs manual clean if tleak or taddress was called before
.PHONY: tvalgr
tvalgr: $(TEST)
	@valgrind --leak-check=full\
			--show-leak-kinds=all\
			--trace-children=no\
			--track-fds=no\
			./$(TEST)
#			--log-file=valgrind-out.txt\
#	@less ./valgrind-out.txt

# ******************************
# *     Object compiling and   *
# *     dependecy creation     *
# ******************************

# Create object and dependency files
# $(DEP_DIR)/%.d =	Declare the generated dependency file as a prerequisite of the target,
# 					so that if it’s missing the target will be rebuilt.
# | $(DEPDIR) = 	Declare the dependency directory as an order-only prerequisite of the target,
# 					so that it will be created when needed.
# $(POSTCOMPILE) =	Move temp dependency file and touch object to ensure right timestamps.
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEP_DIR)/%.d message | $(DEP_DIR)
	$(COMPILE) $< -o $@
	$(POSTCOMPILE)

# Print message only if there are objects to compile
.INTERMEDIATE: message
message:
	@printf "\n$(YELLOW)$(BOLD)compile objects$(RESET) [$(BLUE)philo$(RESET)]\n"

# Create objects from test source files
$(TEST_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Create directory obj/dep if it doesn't exist
$(DEP_DIR):
	@printf "\n$(YELLOW)$(BOLD)create subdir$(RESET) [$(BLUE)philo$(RESET)]\n"
	mkdir -p $@

# Mention each dependency file as a target, so that make won’t fail if the file doesn’t exist.
$(DEPFILES):

# ******************************
# *     Cleanup                *
# ******************************

.PHONY: clean
clean:
	@printf "$(YELLOW)$(BOLD)clean$(RESET) [$(BLUE)philo$(RESET)]\n"
	@rm -rf $(OBJ_DIR)
	@printf "$(RED)removed subdir $(OBJ_DIR)$(RESET)\n"

# Clean test objects and tester
.PHONY: tclean
tclean:
	@rm -rf $(TEST_DIR)/*.o
	@printf "$(RED)removed .o files in subdir $(TEST_DIR)$(RESET)\n"
	@rm -rf $(TEST)
	@printf "$(RED)clean bin $(TEST)$(RESET)\n"

.PHONY: fclean
fclean: clean tclean
	@rm -rf $(NAME)
	@printf "$(RED)clean bin $(NAME)$(RESET)\n"

# ******************************
# *     Recompilation          *
# ******************************

.PHONY: re
re: fclean all

# ******************************
# *     Various                *
# ******************************

# Include the dependency files that exist. Use wildcard to avoid failing on non-existent files.
# Needs to be last target
include $(wildcard $(DEPFILES))
