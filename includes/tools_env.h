/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_env.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 14:48:20 by basle-qu          #+#    #+#             */
/*   Updated: 2015/10/20 14:48:24 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_ENV_H
# define TOOLS_ENV_H

# include "ft_minishell1.h"

t_env	*ft_add_link(t_env *e, char *s1, char *s2);
void	ft_print_env(t_env	*env);
int		char_in_tab(char **tab, char c);
t_env	*var_del(t_env *e, char *name, int n);
int		find_list(char *str, t_env *e);

#endif
