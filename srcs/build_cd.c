
#include "libft.h"
#include "tools.h"
#include "tools_env.h"

char	**ft_cd(char **e, char **cmd)
{
	int		i;
	char	*dir;
	char	*tmp;
	char	*tmp2;
	char	**name;

	i = 0;
	name = recup_name(e);
	dir = NULL;
	while (ft_strcmp("PWD", name[i]))
		i++;
	dir = getcwd(dir,ft_strlen(e[i]));
	free(e[i]);
	tmp = ft_strdup(cmd[1]);
	tmp2 = ft_strjoin("PWD=", tmp);
	e[i] = ft_strdup(tmp2);
	i = 0;
	while (ft_strcmp("OLDPWD", name[i]))
		i++;
	if (chdir(cmd[1]) == -1)
	{
		write(2, "cd: no such file or directory: ", 31);
		write(2, cmd[1], ft_strlen(cmd[1]));
		write(2, "\n", 1);
	}
	tmp2 = ft_strjoin("OLDPWD=", dir);
	e[i] = ft_strdup(tmp2);
	free(tmp);
	free(tmp2);
	free(dir);
	free_tab(name);
	return (e);
}
