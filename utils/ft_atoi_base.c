/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:11:55 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/11 18:39:10 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_atoi(char *str)
{
	int	neg;
	int	rt;

	neg = 1;
	rt = 0;
	while ((*str >= 8 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		rt = rt * 10 + (*str - 48);
		str++;
	}
	return (rt * neg);
}