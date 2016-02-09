#ifndef	LEMIN_H_
# define LEMIN_H_

# define SUCCESS	0
# define FAILURE	-1

/*
** macros for t_anthill.flag
*/

# define NONE		0
# define START		1
# define END		2
# define USELESS	3

# define IS_A_PIPE	4

# define EMPTY		0
# define NOT_EMPTY	1

# define OCCUPED	1
# define NOT_OCCUPED	0

# define YES		1
# define NO		-1

/*
** macros for error messages
*/

# define ERROR_ANTS_NB	"Invalid ants number\n"
# define ERROR_ROOM	"An invalid room has been found\n"
# define ERROR_NO_END	"No exit found in the anthill\n"
# define ERROR_NO_START	"No start found in the anthill\n"
# define DOUBLE_END	"Multiple definition of end room\n"
# define DOUBLE_START	"Multiple definition of start room\n"
# define DOUBLE_ROOM	"Multiple definition of some room\n"
# define NO_PIPE	"There is no connection between rooms\n"
# define MALLOC_FAILED	"Malloc failed, lem-in can't runing\n"
# define NO_ROOM	"There is no room in the map\n"
# define INVALID_PIPE	"The pipe is invalid\n"

typedef struct		s_pos
{
  int			x;
  int			y;
}			t_pos;

typedef struct		s_list_pipe
{
  char			*first;
  char			*second;
  struct s_list_pipe	*next;
}			t_list_pipe;

typedef struct		s_anthill
{
  struct s_anthill	**pipes;
  struct s_anthill	*next;
  char			*name;
  t_pos			pos;
  char			flag;
  char			empty;
  unsigned int 		occuped;
  int			nb_pipe;
  int			to_malloc;
  int			range;
  char			in_a_way;
  int			nb_ant;
  int			djikstra_close;
}			t_anthill;

typedef struct		s_infos
{
  t_anthill		*anthill;
  t_anthill		*first;
  t_anthill		*end;
  int			begin_ants;
  int			remaining_ants;
  int			begin_ant;
}			t_infos;

typedef struct		s_int_list
{
  int			i;
  struct s_int_list    	*next;
  struct s_int_list    	*prev;
}			t_int_list;

/*
** lib functions
*/

int		my_getnbr(char *str);
void		my_putnbr(int nb, const int fd);
int		my_strlen(char *str);
void		my_putchar(char c, const int fd);
void		my_putstr(char *str, const int fd);

void		my_putline(char *str, const int fd);

int		check_if_only_nbr(char *str);
int		my_perror(char *str);
int		my_isin(char *str, char c);
int		check_if_nbr(char *str);

char		**my_str_to_wordtab(char *str, char *c);
int		free_wordtab(char **wordtab);
int		wordtab_count(char **wordtab);

void		put_wordtab(char **wordtab);

int		my_strcmp(char *s1, char *s2);

char		*my_strdup(char *str);
char		*my_strndup(char *str, int n);
char		*my_strpdup(char *str, int i, int j);
char		*my_strcpy(char *str, char *cpy);

void		my_free_tab(char **tab);
char		**my_tab_dup(char **tab);
int		my_size_tab(char **tab);

/*
** lem-in functions
*/

/*
**		algo.c
*/

int		algo(t_infos *infos);

/*
**		parser.c
*/

int		parser(t_infos *infos);
void		del_com_in_line(char *str);

/*
**		parser_rooms.c
*/
int		parser_rooms(t_anthill **anthill,
			     t_list_pipe **tmp_pipe);

/*
**		check_rooms.c
*/

int		check_duplicates(t_anthill *anthill);

/*
**	        parser_pipes.c
*/

int		parser_pipes(t_list_pipe **tmp_pipe,
			     t_anthill **anthill);

/*
**		command.c
*/

int		is_command(char *readed);

/*
**		valid.c
*/

int		room_valid(char **tab, t_anthill **anthill, int *flag);
int		pipe_valid(char **tab,
			   t_list_pipe **tmp_pipe,
			   t_anthill **anthill);

/*
**		check_pipe.c
*/

char		**cut_for_pipe(char *str);
int		check_if_pipe_valid(char **tab,
				    t_anthill **anthill,
				    t_list_pipe **tmp_pipe,
				    t_list_pipe *new);

/*
**		put_pipe_in_anthill.c
*/

int		put_pipe_in_anthill(t_infos *info,
				    t_anthill *anthill,
				    t_list_pipe *tmp_pipe);

/*
**		djikstra.c
*/

t_int_list	**djikstra(t_infos *info);

/*
**		load_the_djikstra.c
*/

void		check_useless(t_anthill *anthill);
t_int_list	*load_the_djikstra(t_infos *infos);

/*
**		get_the_djikstra.c
*/

int		get_the_way(t_anthill *nearest_end);
int		get_the_djikstra(t_anthill *anthill,
				 t_int_list **int_list);

/*
**		get_the_direct.c
*/

int		get_the_direct(t_infos *info,
			       t_int_list **int_list,
			       unsigned int *i);

/*
**		free_list.c
*/

void		free_anthill(t_anthill *list);
void		free_tmp_pipe(t_list_pipe *list);

/*
**		check_init.c
*/

int		check_init(t_infos *infos);

/*
**		display_ant.c
*/

void		display_ant(t_infos *infos,
			    t_int_list **int_list,
			    int a);

#endif /* !LEMIN_H_ */
