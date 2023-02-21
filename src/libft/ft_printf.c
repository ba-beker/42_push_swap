/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:20:42 by mobabeke          #+#    #+#             */
/*   Updated: 2023/02/20 18:01:33 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		length;
	va_list	ap;

	i = 0;
	length = 0;
	va_start(ap, str);
	if (ft_strchr((char *)str, '%') == 0)
	{
		ft_putstr_fd((char *)str, 1);
		return (ft_strlen(str));
	}
	while (str[i])
	{
		if (str[i] != '%')
			length += write(1, &str[i], 1);
		else
		{
			length += ft_check_format(ap, str[i + 1]);
			i++;
		}
		i++;
	}
	va_end(ap);
	return (length);
}
