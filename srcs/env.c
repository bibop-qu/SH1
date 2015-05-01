/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/01 15:41:46 by basle-qu          #+#    #+#             */
/*   Updated: 2015/05/01 16:10:13 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tools.h"
#include "tools_env.h"

void	ft_aff_env(char **e)
{
	while (*e)
	{
		ft_putendl(*e);
		e++;
	}
}

char	**ft_unsetenv(char **e, char **cmd)
{
	int		i;
	char	**var;

	i = 0;
	var = recup_name(e);
	while (var[i] && cmd)
	{
		ft_putendl(var[i]);
		i++;
	}
	return (e);
}

char	**ft_setenv(char **e, char **cmd)
{
	int		i;
	int		arg;
	char	*tmp;

	i = 0;
	arg = tab_size(cmd);
	if (arg > 3)
		write(2, "Wrong number of arguments !!\n", 29);
	else
	{
		tmp = ft_strjoin(cmd[1], "=");
		while (e[i])
			i++;
		if (arg == 3 && find_tab(cmd[1], recup_name(e)))
			e = var_replace(e, cmd[1], ft_strjoin(tmp, cmd[2]));
		else if (arg == 3 && find_tab(cmd[1], recup_name(e)))
			e = var_replace(e, cmd[1], tmp);
		else if (arg == 3 && !find_tab(cmd[1], recup_name(e)))
			e = ft_realloc(e, ft_strjoin(tmp, cmd[2]));
		else if (arg == 2&& !find_tab(cmd[1], recup_name(e)))
			e = ft_realloc(e, tmp);
	}
	return (e);
}

char	**init_env(char **env)
{
	int		i;
	int		size;
	char	**e;

	i = -1;
	size = 0;
	while (env[size])
		size++;
	e = (char**)malloc(sizeof(char*) * (size + 1));
	while (++i < size)
		e[i] = ft_strdup(env[i]);
	e[i] = NULL;
	return (e);
}
