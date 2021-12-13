/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 07:55:26 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/12 21:51:30 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_pid = 0;

void	end_of_call(char bit, int pid)
{
	static int	zero;

	if (bit == '0')
	{
		zero++;
		if (zero == 8)
			kill(pid, SIGUSR1);
	}
	else
		zero = 0;
}

void	send_bit(char bit, int pid)
{
	static int	i;
	static char	sms[9];

	if (g_pid != pid)
	{
		g_pid = pid;
		i = 0;
	}
	sms[i] = bit;
	if (g_pid == pid)
	{
		i++;
		if (i == 9)
		{
			sms[i] = 0;
			ft_printf("%c", to_ascii(sms));
			i = 0;
		}
		end_of_call(bit, pid);
	}
}

void	sigtype(int sig, siginfo_t *data, void *pp)
{
	int	pid;

	pid = data->si_pid;
	if (sig == SIGUSR1)
		send_bit('0', pid);
	else if (sig == SIGUSR2)
		send_bit('1', pid);
}

int	main(void)
{
	struct sigaction	sigs;

	ft_printf("----%d----\n", getpid());
	sigs.sa_sigaction = sigtype;
	sigs.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sigs, NULL);
	sigaction(SIGUSR2, &sigs, NULL);
	while (1)
	{
		sleep(1);
	}	
}
