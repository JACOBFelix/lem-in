SRCS	= lib/basic_functions.c \
	  lib/check.c \
	  lib/get_next_line.c \
	  lib/my_isin.c \
	  lib/my_str_to_wordtab.c \
	  lib/my_strcmp.c \
	  lib/my_strdup.c \
	  lib/put_wordtab.c \
	  lib/putline.c \
	  srcs/algo.c \
	  srcs/command.c \
	  srcs/check_pipe.c \
	  srcs/check_rooms.c \
	  srcs/djikstra.c \
	  srcs/display_ant.c \
	  srcs/get_the_djikstra.c \
	  srcs/get_the_direct.c \
	  srcs/free_list.c \
	  srcs/load_the_djikstra.c \
	  srcs/main.c \
	  srcs/parser.c \
	  srcs/parser_pipes.c \
	  srcs/parser_rooms.c \
	  srcs/put_pipe_in_anthill.c \
	  srcs/valid.c \
	  srcs/check_init.c

OBJS	= $(SRCS:.c=.o)

NAME	= lem_in

CC	= cc

CFLAGS	+= -W -Wall -Wextra -pedantic -ansi -g3
CFLAGS	+= -I includes/

RM	= rm -f

%.o:		%.c
		@printf "[\033[0;32mdone\033[0m] % 50s\n" $<
		@$(CC) -c -o $@ $< $(CFLAGS)

all:		$(NAME)

$(NAME):	$(OBJS)
		@$(CC) -o $(NAME) $(OBJS)

clean:
		@printf "[\033[0;31mdeleted\033[0m] % 47s\n" $(OBJS)
		@$(RM) $(OBJS)

fclean:		clean
		@$(RM) $(NAME)
		@printf "[\033[0;31mdeleted\033[0m] % 47s\n" $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
