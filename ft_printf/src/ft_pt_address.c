/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pt_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:29:09 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/11/28 12:40:19 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk.h"

static int	ft_putnbr_pt_unsigned(unsigned long int num, char *base)
{
	if (num < ft_strlen(base))
		ft_putchar(base[num]);
	else
	{
		ft_putnbr_pt_unsigned(num / ft_strlen(base), base);
		ft_putchar(base[num % ft_strlen(base)]);
	}
	if (num == 0)
		return (1);
	return (base_num_len(num, ft_strlen(base)));
}

int	ft_pt_address(void *addr)
{
	size_t	pt;

	pt = (size_t)addr;
	write(1, "0x", 2);
	return (2 + ft_putnbr_pt_unsigned(pt, "0123456789abcdef"));
}
