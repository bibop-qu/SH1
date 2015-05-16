
#include "libft.h"
#include "tools.h"

char	**recup_path(char **e)
{
	char	*line;
	char	**path;

	while (*e)
	{
		if (!ft_strncmp(*e, "PATH=", 5))
			line = ft_strdup(*e + 5);
		e++;
	}
	path = ft_strsplit(line, ':');
	return (path);
}

void	do_fork(char **cmd, char **e, char **path)
{
	int		i;
	pid_t	pid;
	char	*tmp;
	char	*bin;

	i = 0;
	pid = fork();
	if (pid == 0)
	{
		while (path[i])
		{
			tmp = ft_strjoin(path[i], "/");
			bin = ft_strjoin(tmp, cmd[0]);
			free(tmp);
			if (execve(bin, cmd, e) == -1)
				i++;
			else if (path[i] == NULL)
			{
				write(2, cmd[0], ft_strlen(cmd[0]));
				write(2, ": command not found\n", 20);
				exit(1);
			}
		}
	}
	else
		wait(NULL);
}
