/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 11:35:01 by basle-qu          #+#    #+#             */
/*   Updated: 2015/04/29 14:06:54 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "env.h"
#include "tools.h"
#include "exec.h"

int		main(int ac, char **av, char **env)
{
	char	**e;
	char	*line;
	char	**cmd;
	char	**path;

	line = NULL;
	path = NULL;
	if (ac == 1 && av)
		e = init_env(env);
	while (42)
	{
		ft_putstr("$> ");
		get_next_line(0, &line);
		cmd = ft_strsplit(line, ' ');
		if (!ft_strcmp(cmd[0], "exit"))
			exit(0);
		else if(!ft_strcmp(cmd[0], "env"))
			ft_aff_env(e);
		else if(!ft_strcmp(cmd[0], "setenv"))
			e = ft_setenv(e, cmd);
		else if(!ft_strcmp(cmd[0], "unsetenv"))
			e = ft_unsetenv(e, cmd);
		else
		{
			path = recup_path(e);
			do_fork(cmd, e, path);
		}
		free(line);
		free(path);
		free_tab(cmd);
	}
	return (0);
}
