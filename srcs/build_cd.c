
#include "ft_minishell1.h"
#include "libft.h"
#include "tools.h"
#include "tools_env.h"
#include "env.h"

t_env	*ft_cd(t_env *e, char **cmd)
{
	char	**tab;
	char	*path;
	t_env	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = e;
	path = NULL;
	if ((tab = (char**)malloc(sizeof(char*) * 4)) == 0)
		return (NULL);
	tab[0] = ft_strdup("cd");
	tab[1] = ft_strdup("OLDPWD");
	i = find_list("PWD", e);
	while (++j < i)
		tmp = tmp->next;
	tab[2] = (char*)malloc(sizeof(char) * ft_strlen(tmp->value));
	tab[2] = getcwd(tab[2], 200);
	tab[3] = NULL;
	path = ft_strjoin(tab[2], "/");
	if(cmd[1] && ft_strchr(cmd[1], '/') && chdir(cmd[1]) != 0)
	{
		ft_putendl("la tete a toto tu la dans le dos");
		ft_putendl("la tete a tutu tu la dans le ...");
	}
	if(cmd[1] && !ft_strchr(cmd[1], '/') && chdir(ft_strjoin(path, cmd[1])) != 0)
	{
		ft_putendl("la tete a toto tu la dans le dos");
		ft_putendl("la tete a tutu tu la dans le ...");
	}
	ft_setenv(e, tab);
	tab[1] = ft_strdup("PWD");
	if (!cmd[1])
	{
		tmp = e;
		j = 0;
		i = find_list("HOME", e);
		while (++j < i)
			tmp = tmp->next;
		tab[2] = ft_strdup(tmp->value);
		chdir(tmp->value);
	}
	else
		tab[2] = getcwd(tab[2], 200);
	ft_setenv(e, tab);
	free_tab(tab);
	free(path);
	return (e);
}
