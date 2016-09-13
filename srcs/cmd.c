/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/13 19:19:13 by basle-qu          #+#    #+#             */
/*   Updated: 2016/09/13 19:20:27 by basle-qu         ###   ########.fr       */
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

int		ft_count(const char *s, char c)
{
	int	i;
	int counter;

	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
			counter++;
		i++;
	}
	return (counter);
}

void	if_quote(const char *s, size_t *i, size_t *len)
{
	*i = *i + 1;
	while (s[*i + *len] && (s[*i + *len] != '"'))
	{
		*len = *len + 1;
		if (!s[*i + *len])
			ft_putendl("SYNTAX ERROR");
	}
}

char	**ft_quotesplit(const char *s, char c)
{
	char		**ret;
	size_t		i;
	size_t		j;
	size_t		len;

	ret = ft_memalloc(sizeof(char *) * (ft_count(s, c) + 1));
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len = 0;
			if (s[i] == '"')
				if_quote(s, &i, &len);
			else
				while (s[i + len] && (s[i + len] != c))
					len++;
			ret[j++] = ft_strsub(s, i, len);
			i = i + len;
		}
	}
	ret[j] = NULL;
	return (ret);
}

char	**final_cmd(char *line)
{
	char	**result;

	result = NULL;
	if (!ft_strchr(line, '"'))
		result = ft_strsplit(line, ' ');
	else
		result = ft_quotesplit(line, ' ');
	return (result);
}
