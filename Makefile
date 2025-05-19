# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuknakas <yuknakas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/19 15:45:46 by yuknakas          #+#    #+#              #
#    Updated: 2025/05/19 15:47:48 by yuknakas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CCW			=	cc -Wall -Wextra -Werror

TEST_NAME	=	test.out
TEST_SRCS	=	*.c

test: $(TEST_NAME)

$(TEST_NAME):  $()