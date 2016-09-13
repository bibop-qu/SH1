/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 16:57:08 by basle-qu          #+#    #+#             */
/*   Updated: 2016/09/13 19:23:42 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"
#include "libft.h"
#include "tools.h"
#include "tools_env.h"

char	*ft_add_char(char *line, char c)
{
	char	*result;
	int		i;

	i = -1;
	if (!line)
	{
		result = (char*)malloc(sizeof(char) * 2);
		result[0] = c;
		result[1] = '\0';
		return (result);
	}
	else
		result = (char*)malloc(sizeof(char) * ft_strlen(line) + 2);
	while (line[++i])
		result[i] = line[i];
	result[i] = c;
	result[i + 1] = '\0';
	free(line);
	return (result);
}

char	*one_dol(t_env *e, char *tmp, char *result)
{
	char	*tmp2;
	t_env	*tenv;

	tenv = e;
	while (tenv)
	{
		if (!ft_strcmp(tmp, tenv->name))
		{
			tmp2 = ft_strdup(tenv->value);
			result = ft_strjoin(result, tmp2);
		}
		tenv = tenv->next;
	}
	free(tmp2);
	return (result);
}

char	*ft_replace_dol(char *line, t_env *e)
{
	char	*result;
	char	*tmp;
	int		i;
	int		n;

	i = -1;
	result = ft_strdup("");
	while (line[++i])
	{
		n = 0;
		if (line[i] && line[i] == '$')
		{
			i++;
			while (ft_isalnum(line[i + n]))
				n++;
			tmp = ft_strsub(line, i, n);
			if (find_list(tmp, e))
				result = one_dol(e, tmp, result);
		}
		else
			result = ft_add_char(result, line[i]);
		i = i + n;
	}
	free(tmp);
	return (result);
}

void	ft_echo(char **cmd, t_env *e)
{
	int		i;
	char	*tmp;

	i = 1;
	while (cmd[i] && e)
	{
		if (ft_strchr(cmd[i], '$'))
		{
			tmp = ft_replace_dol(cmd[i], e);
			ft_putstr(tmp);
			free(tmp);
		}
		else
			ft_putstr(cmd[i]);
		if (cmd[i + 1])
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}
