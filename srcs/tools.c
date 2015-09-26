
#include "libft.h"
#include "ft_minishell1.h"

int		tab_size(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	free_list(t_env *e)
{
	t_env		*tmp;

	tmp = e;
	while (tmp)
	{
		free(tmp->name);
		free(tmp->value);
		tmp = tmp->next;
	}
}

void	free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
