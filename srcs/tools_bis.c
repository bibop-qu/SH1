/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 13:24:03 by basle-qu          #+#    #+#             */
/*   Updated: 2016/02/25 20:20:04 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"
#include "libft.h"
#include "tools_env.h"

char	*ft_in_env(t_env *e, char *name)
{
	t_env	*tmp;

	tmp = e;
	while (tmp)
	{
		if (!ft_strcmp(name, tmp->name))
			return (name);
		tmp = tmp->next;
	}
	return (NULL);
}

char	*ft_value(t_env *e, char *name)
{
	t_env	*tmp;
	char	*result;

	result = NULL;
	tmp = e;
	while (tmp)
	{
		if (!ft_strcmp(name, tmp->name))
			result = ft_strdup(tmp->value);
		tmp = tmp->next;
	}
	return (result);
}

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

	i = 0;
	home = NULL;
	if (ft_value(e, "HOME") != NULL)
		home = ft_strdup(ft_value(e, "HOME"));
	result = ft_strdup(line);
	while (ft_strchr(result, '~') && home)
		result = ft_rep(result, home);
	return (result);
}
