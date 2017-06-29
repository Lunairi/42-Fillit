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
INCLUDE = includes/

# For shared library
CFLAGS = -g -Wall -Werror -Wextra -I$(INCLUDE)

# -------------- Automated Variables ---------------- #
# Fucking norm
#SRC = $(wildcard $(addsuffix *.c, $(SRC_DIRS)))
SRC = inprogress/mlu_main.c \
inprogress/dans_case.c \
inprogress/shape_parsing.c \
inprogress/parser.c \
inprogress/shape_validate.c \
inprogress/recursive.c \
inprogress/gridtest.c \
inprogress/grid.c \

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
