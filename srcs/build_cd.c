/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 17:04:56 by basle-qu          #+#    #+#             */
/*   Updated: 2015/10/14 21:42:30 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell1.h"
#include "libft.h"
#include "tools.h"
#include "tools_env.h"
#include "env.h"

void	ft_replace(char *name, char *val, t_env *e)
{
	int		i;
	t_env	*tmp;

	i = find_list(name, e);
	tmp = e;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	free(tmp->value);
	tmp->value = ft_strdup(val);
}

void	ft_back(t_env *e, char *in, char *old)
{
	ft_replace("PWD", old, e);
	ft_replace("OLDPWD", in, e);
	if (chdir(old) == -1)
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(old);
	}
}

void	ft_home(t_env *e, char *in)
{
	int		i;
	char	*home;
	t_env	*tmp;

	i = find_list("HOME", e);
	tmp = e;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	home = ft_strdup(tmp->value);
	if (chdir(home) == -1)
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(home);
	}
	ft_replace("PWD", home, e);
	ft_replace("OLDPWD", in, e);
}

void	ft_move(t_env *e, char *in, char *go)
{
	char	*tmp;
	char	*path;

	if (ft_strchr(go, '/'))
	{
		ft_replace("PWD", go, e);
		ft_replace("OLDPWD", in, e);
		if (chdir(go) == -1)
		{
			ft_putstr("cd: no such file or directory: ");
			ft_putendl(go);
		}
	}
	else
	{
		tmp = ft_strjoin(in, "/");
		path = ft_strjoin(tmp, go);
		ft_replace("PWD", path, e);
		ft_replace("OLDPWD", in, e);
		if (chdir(path) == -1)
		{
			ft_putstr("cd: no such file or directory: ");
			ft_putendl(go);
		}
	}
}

t_env	*ft_cd(t_env *e, char **cmd)
{
	int		i;
	char	*in;
	char	*go;
	char	*old;
	t_env	*tmp;

	in = NULL;
	in = getcwd(in, 200);
	i = find_list("OLDPWD", e);
	tmp = e;
	while (--i > 0)
		tmp = tmp->next;
	old = ft_strdup(tmp->value);
	if (!cmd[1])
		ft_home(e, in);
	else if (!ft_strcmp("-", cmd[1]))
		ft_back(e, in, old);
	else if (cmd[1])
	{
		go = ft_strdup(cmd[1]);
		ft_move(e, in, go);
	}
	return (e);
}
