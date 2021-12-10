/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rj3olia_binary_lay7fdk.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:38:11 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/09 07:25:58 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"

char	*ft_strrev(char *str)
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

char	*rj3olia_binary_lay7fdk(int ascii)
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
		printf("%c\n", bin[i]);
		i++;
	}
	bin[i] = '\0';
	printf("---------new char--------");
	return (ft_strrev(bin));
}
