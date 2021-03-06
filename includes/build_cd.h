/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cd.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 14:43:39 by basle-qu          #+#    #+#             */
/*   Updated: 2016/09/14 21:16:15 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_CD_H
# define BUILD_CD_H

t_env	*ft_cd(t_env *e, char **cmd);
void	ft_replace(char *name, char *val, t_env *e);

#endif
