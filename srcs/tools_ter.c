/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_ter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/14 21:04:59 by basle-qu          #+#    #+#             */
/*   Updated: 2016/09/15 17:33:31 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_minishell1.h"
#include "build_cd.h"

void	ft_slash_move(t_env *e, char *in, char *go)
{
	ft_replace("PWD", go, e);
	ft_replace("OLDPWD", in, e);
	if (chdir(go) == -1)
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(go);
	}
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

void	nm_ft_quotesplit(size_t *len, size_t *i, const char *s, char c)
{
	*len = 0;
	if (s[*i] == '"')
		if_quote(s, i, len);
	else
		while (s[*i + *len] && (s[*i + *len] != c))
			*len = *len + 1;
}
