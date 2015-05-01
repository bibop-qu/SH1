
#include "libft.h"

int		tab_cmp(char *str, char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (!strcmp(str, tab[i]))
			return(1);
		i++;
	}
	return (0);
}

int		tab_size(char **tab)
{
	int		i;

	i = 0;
	while(tab[i])
		i++;
	return (i);
}
