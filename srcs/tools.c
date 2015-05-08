/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 15:27:13 by basle-qu          #+#    #+#             */
/*   Updated: 2015/05/01 15:27:14 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
