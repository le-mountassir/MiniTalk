/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_num_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:19:51 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/11/27 20:39:20 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minitalk.h"

int	base_num_len(size_t num, size_t base)
{
	int	len;

	len = 0;
	while (num > 0)
	{
		num = num / base;
		len++;
	}
	return (len);
}
