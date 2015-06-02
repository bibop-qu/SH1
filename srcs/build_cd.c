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
	char	*temp;

	temp = NULL;
	tmp = (char**)malloc(sizeof(char*) * 4);
	tmp[0] = ft_strdup("WHALLA");
	tmp[1] = ft_strdup("OLDPWD");
	tmp[2] = getcwd(tmp[2], 256);
	tmp[3] = NULL;
	e = ft_setenv(e, tmp);
	temp = ft_strjoin(tmp[2], "/");
	if (ft_strchr(cmd[1], '/') && chdir(cmd[1]) == -1)
	{
		write(2, "cd: no such file or directory: ", 31);
		write(2, cmd[1], ft_strlen(cmd[1]));
		write(2, "\n", 1);
	}
	else if (!ft_strchr(cmd[1], '/') && chdir(ft_strjoin(temp, cmd[1])) == -1)
	{
		write(2, "cd: no such file or directory: ", 31);
		write(2, ft_strjoin(temp, cmd[1]), ft_strlen(cmd[1]) + ft_strlen(temp));
		write(2, "\n", 1);
	}
	tmp[1] = ft_strdup("PWD");
	tmp[2] = getcwd(tmp[2], 256);
	e = ft_setenv(e, tmp);
	free(temp);
	free_tab(tmp);
	return (e);
}
