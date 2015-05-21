/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 13:40:06 by basle-qu          #+#    #+#             */
/*   Updated: 2015/05/21 16:26:58 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tools.h"
#include "tools_env.h"

char	*ft_point(char **e)
{
	int		i;
	char	*result;
	char	**name;
	char	**path;

	i = 0;
	result = NULL;
	name = recup_name(e);
	while (name[i] && ft_strcmp(name[i], "PWD"))
		i++;
	path = ft_strsplit(e[i], '=');
	result = ft_strjoin(ft_strdup(path[1]), "/");
	free_tab(name);
	free_tab(path);
	return (result);

}

char	**recup_path(char **e)
{
	char	*line;
	char	**path;

	line = NULL;
	while (*e)
	{
		if (!ft_strncmp(*e, "PATH=", 5))
			line = ft_strdup(*e + 5);
		e++;
	}
	path = ft_strsplit(line, ':');
	free (line);
	return (path);
}

void	do_fork(char **cmd, char **e, char **path)
{
	int		i;
	pid_t	pid;
	char	*tmp;
	char	*bin;

	i = 0;
	tmp = NULL;
	bin = NULL;
	pid = fork();
	if (pid == 0)
	{
		if (path == NULL || path[0] == NULL)
		{
			write(2, cmd[0], ft_strlen(cmd[0]));
			write(2, ": command not found\n", 20);
			exit(1);
		}
		while (path[i])
		{
			if (!ft_strchr(cmd[0], '.'))
			{
				tmp = ft_strjoin(path[i], "/");
				bin = ft_strjoin(tmp, cmd[0]);
			}
			else
			{
				tmp = ft_point(e);
				bin = ft_strjoin(tmp, cmd[0] + 2);
			}
			free(tmp);
			if (execve(bin, cmd, e) == -1 && path[i])
				i++;
			if (path[i] == NULL)
			{
				write(2, cmd[0], ft_strlen(cmd[0]));
				write(2, ": command not found\n", 20);
				free(bin);
				exit(1);
			}
		}
	}
	else
		wait(NULL);
}
