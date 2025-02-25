# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaetano <dcaetano@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 17:50:20 by dcaetano          #+#    #+#              #
#    Updated: 2025/02/15 21:36:12 by dcaetano         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM       = rm -rf

OBJS_DIR = obj/

SRCS     = megaphone.cpp

OBJS     = $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

EXEC     = megaphone

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
