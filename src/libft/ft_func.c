/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:34:17 by mobabeke          #+#    #+#             */
/*   Updated: 2023/02/20 18:18:11 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_converto_c(va_list arg)
{
	char	c;

	c = (char) va_arg(arg, int);
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_converto_s(va_list arg)
{
	char	*str;

	str = va_arg(arg, char *);
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_converto_di(va_list arg)
{
	int	x;

	x = va_arg(arg, int);
	ft_putnbr_fd(x, 1);
	return (ft_intlen(x));
}

int	ft_converto_x(va_list arg)
{
	unsigned int	i;

	i = va_arg(arg, int);
	if (i == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	return (ft_converto_hex(i));
}
