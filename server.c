/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 07:55:26 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/09 07:20:10 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"

void sig_type(int num)
{
	if (num == SIGUSR1)
	{
		printf("0\n");
	}
	else if (num == SIGUSR2)
	{
		printf("1\n");
	}
}

int main()
{
	ft_printf("---%d---\n", getpid());
	signal(SIGUSR1, sig_type);
	signal(SIGUSR2, sig_type);
	while (1);
}
