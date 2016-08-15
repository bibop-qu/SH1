/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 14:43:54 by basle-qu          #+#    #+#             */
/*   Updated: 2016/02/26 16:29:49 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "ft_minishell1.h"

void	ft_env(t_env *e, char **cmd, char **env);
t_env	*ft_setenv(t_env **e, char **cmd);
t_env	*ft_unsetenv(t_env **e, char **cmd);

#endif
