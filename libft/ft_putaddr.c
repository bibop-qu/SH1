/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 15:40:58 by basle-qu          #+#    #+#             */
/*   Updated: 2015/04/22 15:06:59 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putaddr(void *ptr)
{
	int						ret;
	unsigned long long int	addr;

	if (ptr == NULL)
	{
		ret = ft_putstring("0x0");
		return (ret);
	}
	addr = (unsigned long long int)ptr;
	write(1, "0x", 2);
	ret = ft_putstring(ft_base("0123456789abcdef", addr)) + 2;
	return (ret);
}
