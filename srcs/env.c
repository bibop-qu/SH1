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

	i = 1;
	var = recup_name(e);
	if (!cmd[1])
		write(2, "Wrong number of arguments !!\n", 29);
	else if (equal_in_tab(cmd))
 		write(2, "Syntaxe error !!\n", 17);
	else
	{
		while (cmd[i])
		{
			if (find_tab(cmd[i], var))
				e = var_del(e, cmd[i]);
			i++;
		}
	}
	free_tab(var);
	return (e);
}

char	**ft_setenv(char **e, char **cmd)
{
	int		arg;
	char	*tmp;
	char	*tmp2;
	char	**name;

	arg = tab_size(cmd);
	name = recup_name(e);
	if (arg > 3 || !cmd[1])
		write(2, "Wrong number of arguments !!\n", 29);
	else if (equal_in_tab(cmd))
 		write(2, "Syntaxe error !!\n", 17);
	else
	{
		tmp = ft_strjoin(cmd[1], "=");
		if (cmd[2])
			tmp2 = ft_strjoin(tmp, cmd[2]);
		else
			tmp2 = NULL;
		if (arg == 3 && find_tab(cmd[1], name))
			e = var_replace(e, cmd[1], tmp2);
		else if (arg == 2 && find_tab(cmd[1], name))
			e =  var_replace(e, cmd[1], tmp);
		else if (arg == 3 && !find_tab(cmd[1], name))
			e = ft_realloc(e, tmp2);
		else if (arg == 2 && !find_tab(cmd[1], name))
			e = ft_realloc(e, tmp);
		free(tmp);
		free(tmp2);
	}
	free_tab(name);
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
