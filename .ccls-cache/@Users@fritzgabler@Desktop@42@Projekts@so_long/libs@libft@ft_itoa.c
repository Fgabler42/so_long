/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:55:48 by fgabler           #+#    #+#             */
/*   Updated: 2023/04/12 11:41:30 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

unsigned int	ft_pow(int y)
{
	unsigned int	pow;
	int				i;

	pow = 1;
	i = 0;
	while (i < y)
	{
		pow *= 10;
		i++;
	}
	return (pow);
}

void	ft_checknum(int num, char *str, unsigned int i)
{
	if (num < 10)
		str[i] = num + '0';
	if (num > 9)
	{
		str[i] = (num % 10) + '0';
		num = num / 10;
		i--;
		ft_checknum(num, str, i);
	}
}

char	*ft_itoa(int n)
{
	char			*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		str = (char *) ft_calloc((ft_intlen(n) + 1), sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '-';
		n *= -1;
		ft_checknum(n, str, ft_intlen(n));
	}
	else
	{
		str = (char *) ft_calloc((ft_intlen(n) + 1), sizeof(char));
		if (!str)
			return (NULL);
		ft_checknum(n, str, ft_intlen(n) - 1);
	}
	return (str);
}
