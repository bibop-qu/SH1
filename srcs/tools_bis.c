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

char	*ft_tild(char *line, t_env *e)
{
	int		i;
	char	*home;
	char	**tab;
	char	*result;
	t_env	*tmp;

	i = find_list("HOME", e);
	tab = ft_strsplit(line, '~');
	tmp = e;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	home = ft_strdup(tmp->value);
	i = 0;
	result = ft_strjoin(tab[i], home);
	while (tab[i])
	{
		if (i != 0 && tab[++i])
			result = ft_strjoin(tab[i], home);
		i++;
	}
	return (result);
}
