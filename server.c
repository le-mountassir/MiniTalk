/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 07:55:26 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/10 00:45:45 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"

void	combine(char bit)
{
	static char	sms[8];
	static int	i;

	sms[i] = bit;
	i++;
	if (i == 8)
	{
		sms[i] = 0;
		printf("str = %s", sms);
		ft_printf("%c", rj3olia_ascii(sms));
		i = 0;
	}
}

void	sig_type(int sig)
{
	if (sig == SIGUSR1)
		combine('0');
	else if (sig == SIGUSR2)
		combine('1');
}

int main()
{
	ft_printf("---%d---\n", getpid());
	signal(SIGUSR1, sig_type);
	signal(SIGUSR2, sig_type);
	while (1);
}
