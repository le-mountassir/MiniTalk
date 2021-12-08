/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 07:55:26 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/08 00:45:58 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"
 

void handler_zero(int num)
{
	num = 0;
	signals_handler(0);
}

void handler_one(int num)
{
	num = 0;
	signals_handler(1);
}

char *signals_handler(int bit)
{
	static char	binary[8];
	*binary = bit;
	
}

int main()
{
	ft_printf(getpid());
	signal(SIGUSR1, handler_zero); // 0
	signal(SIGUSR2, handler_one); // 1
	while(1);
}
