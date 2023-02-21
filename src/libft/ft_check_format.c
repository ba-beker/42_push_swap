/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobabeke <mobabeke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:38:28 by mobabeke          #+#    #+#             */
/*   Updated: 2023/02/20 18:00:09 by mobabeke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_format(va_list arg, char c)
{
	if (c == 'd' || c == 'i')
		return (ft_converto_di(arg));
	else if (c == 'c')
		return (ft_converto_c(arg));
	else if (c == 's')
		return (ft_converto_s(arg));
	else if (c == 'x')
		return (ft_converto_x(arg));
	else if (c == 'X')
		return (ft_converto_cx(arg));
	else if (c == 'p')
		return (ft_converto_p(arg));
	else if (c == 'u')
		return (ft_converto_u(arg));
	else if (c == '%')
		return (printpers('%'));
	return (0);
}
