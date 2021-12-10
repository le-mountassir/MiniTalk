/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:10:00 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/07 08:02:03 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../program.h"

int	ft_putnbr_base(int n, char *base)
{
	long	num;
	int		neg;

	neg = 1;
	num = n;
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
		neg = 10;
	}
	if (num < ft_strlen(base))
	{
		ft_putchar(base[num]);
	}
	else
	{
		ft_putnbr_base(num / ft_strlen(base), base);
		ft_putchar(base[num % ft_strlen(base)]);
	}
	if (n == 0)
		return (1);
	return (base_num_len(num * neg, ft_strlen(base)));
}
