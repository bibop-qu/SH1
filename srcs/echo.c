/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 16:57:08 by basle-qu          #+#    #+#             */
/*   Updated: 2016/08/31 18:35:59 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tools.h"

char	*del_quote(char *line)
{
	char	*result;
	int		i;
	int		k;

	i = 0;
	k = 0;
	result = (char*)malloc(sizeof(char) * ft_strlen(line));
	while (line[i])
	{
		if (line[i] != '"')
		{
			result[k] = line[i];
			k++;
		}
		i++;
	}
	return (result);
}

char	**db_quote(char **tab)
{
	int		i;
	int		k;
	char	**ret;
	char	*tmp;

	i = 0;
	k = 0;
	ret = (char**)malloc(sizeof(char*) * tab_size(tab) + 1);
	while (tab[i])
	{
		tmp = NULL;
		if (!ft_strchr(tab[i], '"'))
			ret[k] = ft_strdup(tab[i]);
		else if (tab[i][0] == '"' && tab[i + 1] && tab[i + 1][ft_strlen(tab[i + 1])] == '"')
		{
			ret[k] = ft_strjoin(tab[i], tab[i + 1]);
			i++;
		}
		else if (ft_strchr(tab[i], '"') && tab[i][0] != '"')
			ret[k] = del_quote(tab[i]);
		i++;
		k++;
	}
	ret[k] = NULL;
	return (ret);
}

char	**final_cmd(char *line)
{
	char	**result;

	result = ft_strsplit(line, ' ');
	if (!ft_strchr(line, '"'))
		return (result);
	else
		result = db_quote(result);
	return (result);
}
