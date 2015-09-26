
#ifndef FT_MINISHELL1
# define FT_MINISHELL1

typedef struct		s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}			t_env;

#endif
