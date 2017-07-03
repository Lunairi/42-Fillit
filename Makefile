#* ************************************************************************** */
#*                                                                            */
#*                                                        :::      ::::::::   */
#*   Makefile                                           :+:      :+:    :+:   */
#*                                                    +:+ +:+         +:+     */
#*   By: jkrause <jkrause@student.42.us.org>        +#+  +:+       +#+        */
#*                                                +#+#+#+#+#+   +#+           */
#*   Created: 2017/04/18 03:42:42 by jkrause           #+#    #+#             */
#*   Updated: 2017/06/11 02:45:14 by jkrause          ###   ########.fr       *#
#*                                                                            */
#* ************************************************************************** */

# ----------------- Configuration ------------------- #
NAME = fillit
#INCLUDE = includes/

# For shared library
CFLAGS = -g -Wall -Werror -Wextra 
#-I$(INCLUDE)

# -------------- Automated Variables ---------------- #
#SRC = $(wildcard $(addsuffix *.c, $(SRC_DIRS)))
SRC = main.c \
	shape_parsing.c \
	parser.c \
	shape_validate.c \
	recursive.c \
	grid.c \
	shape_scanning.c \
	functions.c

# For shared library
OBJ = $(subst .c,.o, $(SRC))

# ------------------- Targets ----------------------- #

all: $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c $^ -o $@

# For shared library
$(NAME): $(OBJ)
	gcc -g $^ -o $@

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
