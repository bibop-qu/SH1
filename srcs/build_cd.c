/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/29 10:44:03 by basle-qu          #+#    #+#             */
/*   Updated: 2015/05/29 14:11:25 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "tools.h"
#include "tools_env.h"
#include "env.h"

char	**ft_cd(char **e, char **cmd)
{
	char	**tmp;

	tmp = (char**)malloc(sizeof(char*) * 4);
	tmp[0] = ft_strdup("toto");
	tmp[1] = ft_strdup("OLDPWD");
	tmp[2] = getcwd(tmp[0], 256);
	tmp[3] = NULL;
	e = ft_setenv(e, tmp);
	free(tmp[1]);
	free(tmp[2]);
	tmp[1] = ft_strdup("PWD");
	tmp[2] = ft_strdup(cmd[1]);
	if (chdir(cmd[1]) == -1)
	{
		write(2, "cd: no such file or directory: ", 31);
		write(2, cmd[1], ft_strlen(cmd[1]));
		write(2, "\n", 1);
	}
	return (e);
}
