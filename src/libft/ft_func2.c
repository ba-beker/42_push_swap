/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:35:54 by mobabeke          #+#    #+#             */
/*   Updated: 2023/02/20 18:00:32 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_converto_hex(size_t n)
{
	char		t;
	static int	i;

	i = 0;
	if (n != 0)
	{
		ft_converto_hex(n / 16);
		if (n % 16 < 10)
			t = n % 16 + 48;
		else
			t = n % 16 - 10 + 'a';
		write(1, &t, 1);
		i++;
	}
	return (i);
}

int	ft_converto_cx(va_list arg)
{
	unsigned int	i;

	i = va_arg(arg, int);
	if (i == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	return (ft_converto_hexupper(i));
}

int	ft_converto_u(va_list arg)
{
	unsigned int	u;

	u = va_arg(arg, unsigned int);
	ft_unputnbr_fd(u, 1);
	return (ft_unintlen(u));
}

int	ft_converto_p(va_list arg)
{
	unsigned long long	i;
	int					j;

	j = 0;
	i = va_arg(arg, unsigned long long);
	if (i == 0)
	{
		ft_putstr_fd("0x0", 1);
		return (3);
	}
	ft_putstr_fd("0x", 1);
	j += 2;
	j += ft_converto_hex(i);
	return (j);
}

int	ft_converto_hexupper(unsigned int n)
{
	char		temp;
	static int	i;

	i = 0;
	if (n != 0)
	{
		ft_converto_hexupper(n / 16);
		if (n % 16 < 10)
			temp = n % 16 + 48;
		else
			temp = n % 16 - 10 + 'a' - 32;
		write(1, &temp, 1);
		i++;
	}
	return (i);
}
