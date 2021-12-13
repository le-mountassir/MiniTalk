/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_binary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:15:20 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/12 17:13:34 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

char	*to_binary(char cara)
{
	int		i;
	char	*byte;

	byte = malloc(sizeof(char) * 10);
	if (!byte)
	{
		ft_printf("Allocation Failed !\n");
		exit(1);
	}
	byte[9] = '\0';
	byte[0] = '0';
	if (cara < 0)
	{
		byte[0] = '1';
		cara *= -1;
	}
	i = 8;
	while (i >= 1)
	{
		byte[i] = cara % 2 + '0';
		cara /= 2;
		i--;
	}
	return (byte);
}
