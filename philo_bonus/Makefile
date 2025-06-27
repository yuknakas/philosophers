# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/19 15:45:46 by yuknakas          #+#    #+#              #
#    Updated: 2025/06/27 10:49:27 by yuknakas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CCW			=	cc -Wall -Wextra -Werror
NAME		=	philo_bonus

SRCS_MAN	=	srcs/01_main.c srcs/02_init_data.c srcs/03_philo.c \
				srcs/04_killer.c srcs/05_print.c srcs/10_error.c \
				srcs/11_utils.c srcs/12_time.c
OBJS_MAN	=	$(SRCS_MAN:.c=.o)

all: $(NAME)

$(NAME): $(OBJS_MAN)
	@$(CCW) $(OBJS_MAN) -O2 -o $(NAME)
	@echo "> Make philo executed in current directory"

%.o: %.c
	@$(CCW) -c $< -o $@

clean:
	@rm -f $(OBJS_MAN)
	@echo "> Make clean executed in current directory"

fclean: clean
	@rm -f $(NAME)
	@echo "> Make fclean executed in current directory"

re: fclean all

.PHONY: all clean fclean re
