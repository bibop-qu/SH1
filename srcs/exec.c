
#include "libft.h"
#include "tools.h"
#include "ft_minishell1.h"

int		size_list(t_env *list)
{
	int		size;
	t_env	*tmp;

	size = 0;
	tmp = list;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	free(tmp);
	return (size);
}

char	**listtotab(t_env *list)
{
	int		i;
	char	**env;
	char	*temp;
	t_env	*tmp;

	i = 0;
	tmp = list;
	env = (char**)malloc(sizeof(char*) * (size_list(list) + 1));
	while (tmp)
	{
		temp = ft_strjoin(tmp->name, "=");
		env[i] = ft_strjoin(temp, tmp->value);
		i++;
		free(temp);
		tmp = tmp->next;
	}
	env[i] = NULL;
	free(tmp);
	return (env);
}

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
	free (line);
	return (path);
}

void	do_fork(char **cmd, t_env *e, char **env)
{
	int		i;
	pid_t	pid;
	char	*tmp;
	char	*bin;
	char	**path;

	path = recup_path(e);
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
	else
	{
		free_tab(path);
		free_tab(env);
		wait(NULL);
	}
}
