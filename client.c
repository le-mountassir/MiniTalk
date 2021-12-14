/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 07:55:23 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/13 21:42:21 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_it(char *sms, int pid)
{
	int	i;

	i = 0;
	while (sms[i])
	{
		if (sms[i] == '0')
			kill(pid, SIGUSR1);
		else if (sms[i] == '1')
			kill(pid, SIGUSR2);
		i++;
		usleep(500);
	}
	free(sms);
}

void	confirm(int sig)
{
	sig = 0;
	ft_printf("im done, i've sent everything\n");
}

void	sms_to_bin(t_storage_unit *unit_2)
{
	int		i;
	int		len;
	int		f;
	char	*tmp;

	i = 0;
	f = 0;
	len = ft_strlen(unit_2->str);
	while (f < len + 1)
	{
		unit_2->rt_bin = to_binary(unit_2->str[f]);
		tmp = unit_2->rt_bin;
		while (*unit_2->rt_bin)
		{
			unit_2->sms[i] = *unit_2->rt_bin;
			i++;
			unit_2->rt_bin++;
		}
		f++;
		free(tmp);
	}
	unit_2->sms[i] = '\0';
}

int	main(int c, char **v)
{
	t_storage_unit	unit_1;

	ft_printf("---%d---\n", getpid());
	if (c == 3)
	{
		signal(SIGUSR1, confirm);
		unit_1.pid = ft_atoi(v[1]);
		if (unit_1.pid == 0)
		{
			ft_printf("wrong pid!!!\n");
			return (0);
		}
		unit_1.str = v[2];
		unit_1.sms = malloc(ft_strlen(unit_1.str) * 10);
		if (!unit_1.sms)
			return (0);
		sms_to_bin(&unit_1);
		send_it(unit_1.sms, unit_1.pid);
	}
}
