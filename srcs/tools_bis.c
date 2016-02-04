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

char	*ft_rep(char *line, char *home)
{
	int		i;
	int		j;
	int		k;
	char	*result;
	
	i = 0;
	j = 0;
	k = 0;
	while (line[i] && line[i] != '~')
		i++;
	result = (char*)malloc(sizeof(char) * i + ft_strlen(home));
	while (j < i)
	{
		result[j] = line[j];
		j++;
	}
	while (home[k])
	{
		result[j] = home[k];
		j++;
		k++;
	}
	while (line[i])
	{
		result[j] = line[i];
		j++;
		i++;
	}
	ft_putendl(result);
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
	ft_putendl(result);
	return (result);
}
