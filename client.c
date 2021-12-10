/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 07:55:23 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/09 07:15:25 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"

int	budget_atoi(char *pid)
{
	int rt;
	rt = 0;
	while (*pid)
	{
		if (*pid <= '9' && *pid >= '0')
			rt = rt * 10 + *pid - 48;
		else
			break; 
		pid++;
	}
	return (rt);
}
void	send_it(char *sms, int pid)
{
	int i;
	
	i = 0;
	printf("\nim send :%s\n", sms);
	while (sms[i])
	{
		if (sms[i] == '0')
		{
			kill(pid, SIGUSR1);
			printf("0");
		}
		else if(sms[i] == '1')
		{
			kill(pid, SIGUSR2);
			printf("1");
		}
		i++;
	}
}

int main(int c, char **v)
{
	t_storage_unit	unit_1;

	if (c == 3)
	{
		unit_1.pid = budget_atoi(v[1]);
		unit_1.str = v[2];
		unit_1.sms = malloc(ft_strlen(unit_1.str) * 8);
		unit_1.rt_bin = malloc(8);
		unit_1.i = 0;
		while (*unit_1.str)
		{
			unit_1.rt_bin = rj3olia_binary_lay7fdk(*unit_1.str);
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
		// printf("%d",unit_1.pid);
		printf("\n%s\n", unit_1.sms);
	}
}