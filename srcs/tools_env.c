/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 17:05:36 by basle-qu          #+#    #+#             */
/*   Updated: 2016/02/26 17:25:09 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "env.h"
#include "ft_minishell1.h"

t_env	*ft_add_link(t_env *e, char *s1, char *s2)
{
	t_env	*new;
	t_env	*tmp;

	new = malloc(sizeof(t_env));
	new->name = ft_strdup(s1);
	if (s2)
		new->value = ft_strdup(s2);
	else
		new->value = NULL;
	new->next = NULL;
	tmp = e;
	if (e == NULL)
		return (new);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		return (e);
	}
}

void	ft_print_env(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		ft_putstr(tmp->name);
		ft_putchar('=');
		if (tmp->value)
			ft_putstr(tmp->value);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}

int		char_in_tab(char **tab, char c)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (ft_strchr(tab[i], c))
			return (1);
		i++;
	}
	return (0);
}

int		find_list(char *str, t_env *e)
{
	int		i;
	t_env	*tmp;

	i = 0;
	tmp = e;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, str))
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (0);
}

t_env	*var_del(t_env *e, char *name, int n)
{
	int		i;
	t_env	*tmp;

	i = 1;
	tmp = e;
	while (name && i < n)
	{
		tmp = tmp->next;
		i++;
	}
	if (tmp->next)
	{
		free(tmp->next->name);
		free(tmp->next->value);
		free(tmp->next);
		if (tmp->next->next)
			tmp->next = tmp->next->next;
		else
			tmp->next = NULL;
	}
	return (e);
}
