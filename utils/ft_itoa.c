/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:54:25 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/11 14:01:03 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

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

static long	n_or_p(long numb)
{
	if (numb > 0)
		return (numb);
	return (numb * -1);
}

static int	int_len(long number)
{
	int	i;

	i = 0;
	while (number > 0)
	{
		number /= 10;
		i++;
	}
	return (i);
}

static char	*num_zero(void)
{
	char	*ar_z;

	ar_z = (char *)malloc(2 * sizeof(char));
	ar_z[0] = '0';
	ar_z[1] = '\0';
	return (ar_z);
}

char	*ft_itoa(int n)
{
	char	*arr;
	size_t	i;
	size_t	len;
	int		neg;
	long	nb;

	if (n == 0)
		return (num_zero());
	neg = 0;
	i = 0;
	if (n < 0)
		neg = 1;
	nb = n_or_p(n);
	len = int_len(nb);
	arr = ft_calloc((len + 1 + neg), sizeof(char));
	if (!arr)
		return (NULL);
	while (i < len)
	{
		arr[i++] = nb % 10 + 48;
		nb /= 10;
	}
	if (neg)
		arr[i] = '-';
	return (ft_strrev(arr));
}
