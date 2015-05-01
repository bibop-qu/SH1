/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 15:27:10 by basle-qu          #+#    #+#             */
/*   Updated: 2015/05/01 16:09:39 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tools.h"

char	**var_replace(char **e, char *name, char *rep)
{
	int		i;
	int		size;

	i = 0;
	size = tab_size(e);
	while (i < size)
	{
		if (!ft_strcmp(name, e[i]))
			e[i] = ft_strdup(rep);
		i++;
	}
	return (e);
}

int		find_tab(char *str, char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (!ft_strcmp(str, tab[i]))
			return (1);
		i++;
	}
	return (0);
}

char	**recup_name(char **e)
{
	int		i;
	int		size;
	char	**name;
	char	**tmp;

	i = 0;
	size = 0;
	while (e[size])
		size++;
	name = (char**)malloc(sizeof(char*) * (size + 1));
	while (i < size)
	{
		tmp = ft_strsplit(e[i], '=');
		name[i] = ft_strdup(tmp[0]);
		i++;
	}
	name[i] = NULL;
	return(name);
}

char	**ft_realloc(char **map, char *line)
{
	int		i;
	char	**result;

	i = 0;
	if (map == NULL)
	{
		result = (char**)malloc(sizeof(char*) * 2);
		result[i] = ft_strdup(line);
		result[i + 1] = NULL;
	}
	else
	{
		while (map[i])
			i++;
		result = (char**)malloc(sizeof(char*) * (i + 2));
		i = -1;
		while (map[++i])
			result[i] = ft_strdup(map[i]);
		result[i] = ft_strdup(line);
		result[i + 1] = NULL;
	}
	return (result);
}
