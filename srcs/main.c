
#include "ft_minishell1.h"
#include "libft.h"
#include "env.h"
#include "get_next_line.h"
#include "tools.h"
#include "tools_env.h"
#include "exec.h"
#include "build_cd.h"

t_env	*init_env(t_env *e, char **env)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = NULL;
	while (env[i])
	{
		tmp = ft_strsplit(env[i], '=');
		e = ft_add_link(e, tmp[0], tmp[1]);
		free_tab(tmp);
		i++;
	}
	return (e);
}

int		main(int ac, char **av, char **env)
{
	t_env	*e;
	char	*line;
	char	**cmd;
	char	**tab_e;

	e = NULL;
	line = NULL;
	tab_e = NULL;
	if (ac >= 1 && av)
		e = init_env(e, env);
	while (42)
	{
		ft_putstr("$> ");
		get_next_line(0, &line);
		cmd = ft_strsplit(line, ' ');
		free(line);
		if (!cmd || cmd[0] == '\0')
			continue ;
		if (!ft_strcmp(cmd[0], "exit"))
		{
			free_list(e);
			exit(0);
		}
		else if (!ft_strcmp(cmd[0], "env"))
			ft_env(e);
		else if (!ft_strcmp(cmd[0], "setenv"))
			e = ft_setenv(e, cmd);
		else if (!ft_strcmp(cmd[0], "unsetenv"))
			e = ft_unsetenv(e, cmd);
		else if (!ft_strcmp(cmd[0], "cd"))
			e = ft_cd(e, cmd);
		else
		{
			tab_e = listtotab(e);
			do_fork(cmd, e, tab_e);
		}
		free_tab(cmd);
	}
	return (0);
}
