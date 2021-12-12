/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 11:33:38 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/11/28 15:36:01 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk.h"

int	var_type(char param, va_list lst)
{
	int	len;

	len = 0;
	if (param == '%')
		len = ft_putchar(param);
	else if (param == 'd' || param == 'i')
		len = ft_putnbr_base(va_arg(lst, int), "0123456789");
	else if (param == 's')
		len = ft_putstr(va_arg(lst, char *));
	else if (param == 'c')
		len = ft_putchar(va_arg(lst, int));
	else if (param == 'x')
		len = ft_putnbr_base_unsigned(va_arg(lst, unsigned int),
				"0123456789abcdef");
	else if (param == 'X')
		len = ft_putnbr_base_unsigned(va_arg(lst, unsigned int),
				"0123456789ABCDEF");
	else if (param == 'p')
		len = ft_pt_address(va_arg(lst, void *));
	else if (param == 'u')
		len = ft_putnbr_base_unsigned(va_arg(lst, unsigned), "0123456789");
	return (len);
}
