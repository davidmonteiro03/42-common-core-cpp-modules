# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/01 17:23:24 by dcaetano          #+#    #+#              #
#    Updated: 2025/04/09 07:37:41 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# === BINARY ================================================================= #

NAME      = convert
LIB       = $(NAME).a

# === COMMANDS =============================================================== #

CPP       = c++
MK        = mkdir
RM        = rm
AR_RCS    = ar rcs

# === DIRECTORIES ============================================================ #

INCS_D    = includes
SRCS_D    = srcs
OBJS_D    = objs

# === EXTENSIONS ============================================================= #

CPP_EXT   = .cpp
HPP_EXT   = .hpp
OBJ_EXT   = .o

# === FILES ================================================================== #

CLASSES   = ScalarConverter
CPPFILES  = $(CLASSES)
HPPFILES  = $(CLASSES)

INCS      = $(addprefix $(INCS_D)/, \
                        $(addsuffix $(HPP_EXT), \
                        $(HPPFILES)))
SRCS      = $(addprefix $(SRCS_D)/, \
                        $(addsuffix $(CPP_EXT), \
                        $(CPPFILES)))
OBJS      = $(patsubst $(SRCS_D)/%$(CPP_EXT), \
                       $(OBJS_D)/$(SRCS_D)/%$(OBJ_EXT), \
                       $(SRCS))

MAIN_CPP  = main$(CPP_EXT)
MAIN_OBJ  = $(patsubst %$(CPP_EXT), \
                       $(OBJS_D)/%$(OBJ_EXT), \
                       $(MAIN_CPP))

# === FLAGS ================================================================== #

CPP_FLAGS = -Wall -Wextra -Werror -std=c++98
MK_FLAGS  = -p
RM_FLAGS  = -rfv

# === RULES ================================================================== #

all: $(NAME)

$(OBJS_D)/%$(OBJ_EXT): %$(CPP_EXT) $(INCS)
	@$(MK) $(MK_FLAGS) $(dir $@) > /dev/null 2>&1
	@$(CPP) $(CPP_FLAGS) -c $< -o $@ > /dev/null 2>&1

$(OBJS_D)/$(SRCS_D)/%$(OBJ_EXT): $(SRCS_D)/%$(CPP_EXT) $(INCS)
	@$(MK) $(MK_FLAGS) $(dir $@) > /dev/null 2>&1
	@$(CPP) $(CPP_FLAGS) -c $< -o $@ > /dev/null 2>&1

$(LIB): $(OBJS)
	@$(AR_RCS) $(LIB) $(OBJS) > /dev/null 2>&1

$(NAME): $(LIB) $(MAIN_OBJ)
	@$(CPP) $(CPP_FLAGS) $(MAIN_OBJ) $(LIB) -o $(NAME) > /dev/null 2>&1

clean:
	@$(RM) $(RM_FLAGS) $(OBJS_D)

fclean: clean
	@$(RM) $(RM_FLAGS) $(NAME) $(LIB)

re: fclean all

.PHONY: all clean fclean re
