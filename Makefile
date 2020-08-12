# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmartin <lmartin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/30 21:31:46 by lmartin           #+#    #+#              #
#    Updated: 2020/08/12 04:45:33 by lmartin          ###   ########.fr        #
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

SRCS			=	main.cpp \
					test_queue.cpp \
					test_stack.cpp \
					test_map.cpp \
					test_list.cpp \
					test_vector.cpp

# COMPILED_SOURCES #

OBJS		=	$(SRCS:%.cpp=$(DIR_OBJS)%.o)

TEST		=	test

# **************************************************************************** #

## RULES ##

all:			$(TEST)

# VARIABLES RULES #


$(TEST):		$(OBJS)
				@printf "\033[2K\r$(_GREEN) All files compiled into '$(DIR_OBJS)'. $(_END)✅\n"
				@$(CC) $(CC_FLAGS) -I $(DIR_HEADERS) $(OBJS) -o $(TEST)
				@printf "$(_GREEN) Executable '$(TEST)' created. $(_END)✅\n"

# COMPILED_SOURCES RULES #

$(OBJS):		| $(DIR_OBJS)

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
				@$(RM) $(TEST)
				@printf "$(_RED) '"$(TEST)"' has been deleted. $(_END)🗑️\n"

re:				fclean all

# BONUS #

bonus:			all

re_bonus:		fclean bonus

# PHONY #

.PHONY:			all clean fclean re bonus re_bonus
