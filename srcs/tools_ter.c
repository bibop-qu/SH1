/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_ter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 21:04:59 by basle-qu          #+#    #+#             */
/*   Updated: 2016/09/14 21:17:31 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_minishell1.h"
#include "build_cd.h"

void	ft_slash_move(t_env	*e, char *in, char *go)
{
	ft_replace("PWD", go, e);
	ft_replace("OLDPWD", in, e);
	if (chdir(go) == -1)
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(go);
	}
}
