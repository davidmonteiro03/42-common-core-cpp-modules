# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 17:50:20 by dcaetano          #+#    #+#              #
#    Updated: 2025/02/15 22:37:01 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM       = rm -rf

OBJS_DIR = obj/

SRCS     = main.cpp

OBJS     = $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

EXEC     = hi_this_is_brain

all: $(EXEC)

$(OBJS_DIR)%.o: ./%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(EXEC): $(OBJS)
	@$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	@$(RM) $(OBJS_DIR)

fclean: clean
	@$(RM) $(EXEC)

re: fclean all

.PHONY: all clean fclean re
