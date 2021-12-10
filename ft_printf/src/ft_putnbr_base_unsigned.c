/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_unsigned.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 20:09:54 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/11/27 20:09:54 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../program.h"

int	ft_putnbr_base_unsigned(unsigned int num, char *base)
{
	if (num < ft_strlen(base))
		ft_putchar(base[num]);
	else
	{
		ft_putnbr_base_unsigned(num / ft_strlen(base), base);
		ft_putchar(base[num % ft_strlen(base)]);
	}
	if (num == 0)
		return (1);
	return (base_num_len(num, ft_strlen(base)));
}
