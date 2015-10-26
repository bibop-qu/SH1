/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 17:05:08 by basle-qu          #+#    #+#             */
/*   Updated: 2015/10/20 14:40:05 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tools.h"
#include "ft_minishell1.h"

char	*ft_point(t_env *e)
{
	int		i;
	t_env	*tmp;
	char	*result;
	char	*path;

	i = 0;
	tmp = e;
	result = NULL;
	while (tmp && ft_strcmp(tmp->name, "PWD"))
		tmp = tmp->next;
	path = ft_strdup(tmp->name);
	result = ft_strjoin(ft_strdup(path), "/");
	free(path);
	return (result);
}

char	**recup_path(t_env *e)
{
	t_env	*tmp;
	char	*line;
	char	**path;

	line = NULL;
	tmp = e;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, "PATH"))
			line = ft_strdup(tmp->value);
		tmp = tmp->next;
	}
	path = ft_strsplit(line, ':');
	free(line);
	return (path);
}

char	*ft_bin(char *path, t_env *e, char **cmd)
{
	char	*tmp;
	char	*bin;

	tmp = NULL;
	bin = NULL;
	if (!ft_strchr(cmd[0], '.'))
	{
		tmp = ft_strjoin(path, "/");
		bin = ft_strjoin(tmp, cmd[0]);
	}
	else
	{
		tmp = ft_point(e);
		bin = ft_strjoin(tmp, cmd[0] + 2);
	}
	free(tmp);
	return (bin);
}

void	ft_pid(char **cmd, char **env, char **path, t_env *e)
{
	int		i;
	char	*bin;

	i = 0;
	bin = NULL;
	execve(cmd[0], cmd, env);
	if (path == NULL || path[0] == NULL)
	{
		write(2, cmd[0], ft_strlen(cmd[0]));
		write(2, ": command not found\n", 20);
		exit(1);
	}
	while (path[i])
	{
		bin = ft_bin(path[i], e, cmd);
		if (execve(bin, cmd, env) == -1 && path[i])
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

void	do_fork(char **cmd, t_env *e, char **env)
{
	char	**path;
	pid_t	pid;

	path = recup_path(e);
	pid = fork();
	if (pid == 0)
		ft_pid(cmd, env, path, e);
	else
	{
		free_tab(path);
		free_tab(env);
		wait(NULL);
	}
}
