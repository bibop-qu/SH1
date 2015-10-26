/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 14:44:38 by basle-qu          #+#    #+#             */
/*   Updated: 2015/10/20 14:45:58 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "ft_minishell1.h"

void	do_fork(char **cmd, t_env *e, char **env);
char	**listtotab(t_env *list);
int		size_list(t_env *list);

#endif
