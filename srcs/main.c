/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 17:05:14 by basle-qu          #+#    #+#             */
/*   Updated: 2016/02/20 17:02:41 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"
#include "libft.h"
#include "env.h"
#include "get_next_line.h"
#include "tools.h"
#include "tools_env.h"
#include "tools_bis.h"
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

void	ft_loop(char **cmd, t_env *e, char **tab_e)
{
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
	else if (!ft_strcmp(cmd[0], "cd") && e)
		e = ft_cd(e, cmd);
	else if (!ft_strcmp(cmd[0], "cd") && !e)
		ft_putendl("build_cd can't run");
	else
	{
		tab_e = listtotab(e);
		do_fork(cmd, e, tab_e);
	}
	free_tab(cmd);
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
		if (ft_strchr(line, '~'))
			line = ft_tild(line, e);
		cmd = ft_strsplit(line, ' ');
		free(line);
		if (!cmd || cmd[0] == '\0')
			continue ;
		ft_loop(cmd, e, tab_e);
	}
	return (0);
}
