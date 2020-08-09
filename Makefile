# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/30 21:31:46 by lmartin           #+#    #+#              #
#    Updated: 2020/08/09 20:43:36 by lmartin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#
## PIMPED MAKEFILE ##

# COLORS #

# This is a minimal set of ANSI/VT100 color codes
_END		=	\e[0m
_BOLD		=	\e[1m
_UNDER		=	\e[4m
_REV		=	\e[7m

# Colors
_GREY		=	\e[30m
_RED		=	\e[31m
_GREEN		=	\e[32m
_YELLOW		=	\e[33m
_BLUE		=	\e[34m
_PURPLE		=	\e[35m
_CYAN		=	\e[36m
_WHITE		=	\e[37m

# Inverted, i.e. colored backgrounds
_IGREY		=	\e[40m
_IRED		=	\e[41m
_IGREEN		=	\e[42m
_IYELLOW	=	\e[43m
_IBLUE		=	\e[44m
_IPURPLE	=	\e[45m
_ICYAN		=	\e[46m
_IWHITE		=	\e[47m

# **************************************************************************** #

## VARIABLES ##

# COMPILATION #

CC			=	clang++

CC_FLAGS	=	-g3 -fsanitize=address -Wall -Wextra -Werror


# DELETE #

RM			=	rm -rf


# DIRECTORIES #

DIR_HEADERS =	./

DIR_SRCS	=	./

DIR_OBJS	=	./compiled_srcs/


# FILES #

MAP_SRC			=	test_map.cpp

MAP_SRCS		=	$(MAP_SRC)

LIST_SRC		=	test_list.cpp

LIST_SRCS		=	$(LIST_SRC)

VECTOR_SRC		=	test_vector.cpp

VECTOR_SRCS		=	$(VECTOR_SRC)

# COMPILED_SOURCES #

MAP_OBJS	=	$(MAP_SRCS:%.cpp=$(DIR_OBJS)%.o)

LIST_OBJS	=	$(LIST_SRCS:%.cpp=$(DIR_OBJS)%.o)

VECTOR_OBJS	=	$(VECTOR_SRCS:%.cpp=$(DIR_OBJS)%.o)

TEST_MAP	=	test_map

TEST_LIST 	=	test_list

TEST_VECTOR =	test_vector

# **************************************************************************** #

## RULES ##

all:			$(TEST_LIST) $(TEST_MAP) $(TEST_VECTOR)

# VARIABLES RULES #

$(TEST_MAP):	$(MAP_OBJS)
				@printf "\033[2K\r$(_GREEN) All files compiled into '$(MAP_OBJS)'. $(_END)✅\n"
				@$(CC) $(CC_FLAGS) -I $(DIR_HEADERS) $(MAP_OBJS) -o $(TEST_MAP)
				@printf "$(_GREEN) Executable '$(TEST_MAP)' created. $(_END)✅\n"

$(TEST_LIST):	$(LIST_OBJS)
				@printf "\033[2K\r$(_GREEN) All files compiled into '$(LIST_OBJS)'. $(_END)✅\n"
				@$(CC) $(CC_FLAGS) -I $(DIR_HEADERS) $(LIST_OBJS) -o $(TEST_LIST)
				@printf "$(_GREEN) Executable '$(TEST_LIST)' created. $(_END)✅\n"

$(TEST_VECTOR):	$(VECTOR_OBJS)
				@printf "\033[2K\r$(_GREEN) All files compiled into '$(VECTOR_OBJS)'. $(_END)✅\n"
				@$(CC) $(CC_FLAGS) -I $(DIR_HEADERS) $(VECTOR_OBJS) -o $(TEST_VECTOR)
				@printf "$(_GREEN) Executable '$(TEST_VECTOR)' created. $(_END)✅\n"

# COMPILED_SOURCES RULES #

$(MAP_OBJS):		| $(DIR_OBJS)

$(LIST_OBJS):		| $(DIR_OBJS)

$(VECTOR_OBJS):		| $(DIR_OBJS)

$(DIR_OBJS)%.o: $(DIR_SRCS)%.cpp
				@$(CC) $(CC_FLAGS) -I $(DIR_HEADERS) -c $< -o $@
				@printf "\033[2K\r $(_YELLOW)Compiling $< $(_END)⌛"

$(DIR_OBJS):
				@mkdir $(DIR_OBJS)


# OBLIGATORY PART #

clean:
				@$(RM) $(DIR_OBJS)
				@printf "$(_RED) '"$(DIR_OBJS)"' has been deleted. $(_END)🗑️\n"

fclean:			clean
				@$(RM) $(TEST_MAP)
				@printf "$(_RED) '"$(TEST_MAP)"' has been deleted. $(_END)🗑️\n"
				@$(RM) $(TEST_LIST)
				@printf "$(_RED) '"$(TEST_LIST)"' has been deleted. $(_END)🗑️\n"
				@$(RM) $(TEST_VECTOR)
				@printf "$(_RED) '"$(TEST_VECTOR)"' has been deleted. $(_END)🗑️\n"

re:				fclean all

# BONUS #

bonus:			all

re_bonus:		fclean bonus

# PHONY #

.PHONY:			all clean fclean re bonus re_bonus
