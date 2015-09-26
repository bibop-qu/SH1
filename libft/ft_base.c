/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 20:28:33 by basle-qu          #+#    #+#             */
/*   Updated: 2015/04/22 15:06:17 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_base(char *set, unsigned long int val)
{
	char				*base;
	unsigned long int	quotient;
	long int			size;
	int					len;

	size = 0;
	quotient = val;
	len = ft_strlen(set);
	while (quotient != 0 && ++size > -1)
		quotient /= len;
	base = (char*)malloc(sizeof(char) * size + 1);
	if (val == 0)
	{
		base = "0";
		return (base);
	}
	base[size] = '\0';
	while (val != 0)
	{
		size--;
		base[size] = set[val % len];
		val /= len;
	}
	return (base);
}
