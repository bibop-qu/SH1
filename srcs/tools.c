/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 17:05:30 by basle-qu          #+#    #+#             */
/*   Updated: 2015/10/14 22:14:00 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_minishell1.h"

int		size_list(t_env *list)
{
	int		size;
	t_env	*tmp;

	size = 0;
	tmp = list;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	free(tmp);
	return (size);
}

char	**listtotab(t_env *list)
{
	int		i;
	char	**env;
	char	*temp;
	t_env	*tmp;

	i = 0;
	tmp = list;
	env = (char**)malloc(sizeof(char*) * (size_list(list) + 1));
	while (tmp)
	{
		temp = ft_strjoin(tmp->name, "=");
		env[i] = ft_strjoin(temp, tmp->value);
		i++;
		free(temp);
		tmp = tmp->next;
	}
	env[i] = NULL;
	free(tmp);
	return (env);
}

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
