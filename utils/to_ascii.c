/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_ascii.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:26:03 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/11 18:40:55 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"
#include <math.h>
static int	ft_pow(int num, int pow)
{
	int	i;
	int	rt;

	rt = num;
	i = 0;
	if (pow == 0)
		return (1);
	if (pow == 1)
		return (num);
	while (i < pow)
	{
		rt *= num;
		i++;
	}
	return (i);
}

int	to_ascii(char *bin)
{
	int	ascii;
	int	i;

	ascii = 0;
	i = 0;
	while (i < 8)
	{
		ascii += (bin[i] - 48) * pow(2, ((8 - i) - 1));
		i++;
	}
	return (ascii);
}
