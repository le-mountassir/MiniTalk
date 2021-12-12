/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 07:55:26 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/12 11:49:33 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(char bit)
{
	static int	i;
	static char	sms[8];
	
	sms[i] = bit;
	i++;
	if (i == 8)
	{
		sms[i] = 0;
		ft_printf("%c", to_ascii(sms));
		i = 0;
	}
}

void	sigtype(int sig, siginfo_t *data, void *pp)
{
	printf("\nclient pid= %d \n", data->si_pid);
	if(sig == SIGUSR1)
		send_bit('0');
	else if (sig == SIGUSR2)
		send_bit('1');
	
}

int	main()
{
	ft_printf("----%d----\n", getpid());
	struct sigaction sigs;
    sigs.sa_sigaction = sigtype;
    sigs.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sigs, NULL);
	sigaction(SIGUSR2, &sigs, NULL);
	while (1)
	{
		sleep(1);
	}	
}
