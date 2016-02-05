/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 13:24:03 by basle-qu          #+#    #+#             */
/*   Updated: 2015/10/26 14:21:15 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"
#include "libft.h"
#include "tools_env.h"

char	**ft_split_one(char *line, char c)
{
	int		i;
	int		j;
	char	**tab;

	i = 0;
	j = 0;
	tab = (char**)malloc(sizeof(char*) * 3);
	while (line[i] && line[i] != c)
		i++;
	tab[0] = (char*)malloc(sizeof(char) * i);
	ft_strncpy(tab[0], line, i);
	tab[1] = (char*)malloc(sizeof(char) * (ft_strlen(line) - i));
	while (line[++i])
	{
		tab[1][j] = line[i];
		j++;
	}
	tab[2] = NULL;
	return (tab);
}

char	*ft_rep(char *line, char *home)
{
	char	**tmp;
	char	*yolo;
	char	*result;

	tmp = ft_split_one(line, '~');
	yolo = ft_strjoin(tmp[0], home);
	result = ft_strjoin(yolo, tmp[1]);
	return (result);
}

char	*ft_tild(char *line, t_env *e)
{
	int		i;
	char	*home;
	char	*result;
	t_env	*tmp;

	i = find_list("HOME", e);
	tmp = e;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	home = ft_strdup(tmp->value);
	i = 0;
	result = ft_strdup(line);
	while (ft_strchr(result, '~'))
	{
		result = ft_rep(line, home);
	}
	return (result);
}
