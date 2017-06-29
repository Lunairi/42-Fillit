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
divert(-1)
## TAKE THAT, NORM.

define(SRC_DIRS, inprogress stable)

define(SRC_DIRS2, patsubst(SRC_DIRS,` ',```,'''))
divert(0)
# For shared library
CFLAGS = -g -Wall -Werror -Wextra -I$(INCLUDE)

# -------------- Automated Variables ---------------- #
# Fucking norm
#SRC = $(wildcard $(addsuffix *.c, $(SRC_DIRS)))
SRC = syscmd(find {SRC_DIRS2} -type f -d 1 -name "*.c" | sed -e "s/$/ \\\/g")
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
