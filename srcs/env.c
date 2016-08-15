/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 17:05:03 by basle-qu          #+#    #+#             */
/*   Updated: 2016/02/26 16:31:06 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tools.h"
#include "tools_env.h"
#include "ft_minishell1.h"
#include "tools_bis.h"
#include "exec.h"

void	ft_env(t_env *e, char **cmd, char **env)
{
	if (cmd[0] && cmd[1] == NULL)
		ft_print_env(e);
	else if (cmd[0] && ft_strcmp(cmd[1], "-i"))
		do_fork(cmd + 1, e, env);
	else if (cmd[0] && !ft_strcmp(cmd[1], "-i"))
		execve(NULL, cmd + 2, NULL);
}

t_env	*ft_unsetenv(t_env **e, char **cmd)
{
	int		i;

	i = 1;
	if (!cmd[1])
		write(2, "Wrong number of arguments !!\n", 29);
	else if (char_in_tab(cmd, '='))
		write(2, "Syntaxe error !!\n", 17);
	else
	{
		while (cmd[i])
		{
			if (ft_in_env(*e, cmd[i]) && find_list(cmd[i], *e) == 0)
			{
				free((*e)->name);
				free((*e)->value);
				*e = (*e)->next;
			}
			else if (ft_in_env(*e, cmd[i]))
				*e = var_del(*e, cmd[i], find_list(cmd[i], *e));
			i++;
		}
	}
	return (*e);
}

void	ft_make(t_env **e, t_env *tmp, char **cmd, int a)
{
	while (tmp)
	{
		if (!ft_strcmp(cmd[1], tmp->name))
		{
			if (cmd[2])
			{
				if (tmp->value)
					free(tmp->value);
				tmp->value = ft_strdup(cmd[2]);
			}
			else
				ft_strclr(tmp->value);
			a = 1;
		}
		tmp = tmp->next;
	}
	if (a == 0 && cmd[2])
		*e = ft_add_link(*e, cmd[1], cmd[2]);
	else if (a == 0 && !cmd[2])
		*e = ft_add_link(*e, cmd[1], "");
}

t_env	*ft_setenv(t_env **e, char **cmd)
{
	int		arg;
	int		a;
	t_env	*tmp;

	arg = tab_size(cmd);
	a = 0;
	tmp = *e;
	if (arg > 3 || !cmd[1])
		write(2, "Wrong number of arguments !!\n", 29);
	else if (char_in_tab(cmd, '='))
		write(2, "Syntaxe error !!\n", 17);
	else
		ft_make(e, tmp, cmd, a);
	return (*e);
}
