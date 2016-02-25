/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bis.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/26 13:46:00 by basle-qu          #+#    #+#             */
/*   Updated: 2016/02/25 20:29:50 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_BIS_H
# define TOOLS_BIS_H

char	*ft_in_env(t_env *e, char *name);
char	*ft_value(t_env *e, char *name);
char	*ft_tild(char *line, t_env *e);

#endif
