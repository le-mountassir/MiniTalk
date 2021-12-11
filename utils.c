/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:38:11 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/10 05:16:32 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"

static int ft_pow(int num, int pow)
{
	int	i;
	int rt;

	rt = num;
	i = 0;
	if (pow == 0)
		return (1);
	if (pow == 1)
		return (num);
	while (i < pow)
	{
		rt *= num;
		i++;
	}
	return (i);
}

static char	*ft_strrev(char *str)
{
	size_t	i;
	size_t	len;
	char	swp;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		swp = str[i];
		str[i] = str[len - 1];
		str[len - 1] = swp;
		len--;
		i++;
	}
	return (str);
}

char	*rj3olia_binary_lay7fdk(char ascii)
{
	char	*bin;
	int		b;
	int		bit;
	int		i;

	i = 0;
	b = 128;
	bin = malloc(8);
	while (ascii > 0 && i < 8)
	{
		if (ascii < b)
			bit = ascii % 2;
		else
		{
			ascii /= 2;
			bit = ascii % 2;
		}
		b /= 2;
		bin[i] = bit + 48;
		i++;
	}
	bin[i] = '\0';
	return (ft_strrev(bin));
}

int rj3olia_ascii(char* bin)
{
	int ascii = 0;
	int i = 0;
	while (i < 8)
	{
		ascii += (bin[i] - 48) * pow(2, ((8 - i) - 1));
		i++;
	}
	return (ascii);
}