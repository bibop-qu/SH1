/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 22:13:39 by basle-qu          #+#    #+#             */
/*   Updated: 2015/10/14 22:14:04 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

#include "ft_minishell1.h"

int		size_list(t_env *list);
char	**listtotab(t_env *list);
int		tab_size(char **tab);
void	free_list(t_env *e);
void	free_tab(char **tab);

#endif
