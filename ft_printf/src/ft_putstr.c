/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 15:10:13 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/11 13:55:20 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk.h"

int	ft_putstr(char *cara)
{
	int	i;

	i = 0;
	if (cara == NULL)
		return (ft_putstr("(null)"));
	while (cara[i])
	{
		ft_putchar(cara[i]);
		i++;
	}
	return (i);
}
