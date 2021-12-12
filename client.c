/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 07:55:23 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/12 11:43:01 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_it(char *sms, int pid)
{
	int i;
	
	i = 0;
	printf("\nim sending : ");
	while (sms[i])
	{
		printf("%c", sms[i]);
		if (sms[i] == '0')
			kill(pid, SIGUSR1);
		else if(sms[i] == '1')
			kill(pid, SIGUSR2);
		i++;
		usleep(500);
	}
}

int main(int c, char **v)
{
	t_storage_unit	unit_1;
	printf("\n---%d---\n", getpid());
	if (c == 3)
	{
		unit_1.pid = ft_atoi(v[1]);
		unit_1.str = v[2];
		unit_1.sms = malloc(ft_strlen(unit_1.str) * 8);
		unit_1.rt_bin = malloc(8);
		unit_1.i = 0;
		while (*unit_1.str)
		{
			unit_1.rt_bin = to_binary(*unit_1.str);
			while (*unit_1.rt_bin)
			{
				unit_1.sms[unit_1.i] = *unit_1.rt_bin;
				unit_1.i++;
				unit_1.rt_bin++;
			}
			unit_1.str++;
		}
		unit_1.sms[unit_1.i] = '\0';
		send_it(unit_1.sms, unit_1.pid);
	}
}

