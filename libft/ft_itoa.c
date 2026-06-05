/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 08:48:00 by czuluaga          #+#    #+#             */
/*   Updated: 2026/04/21 15:36:38 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_of_digits(int n)
{
	int	ndigits;

	ndigits = 1;
	if (n < 0)
		ndigits++;
	while (n / 10)
	{
		n /= 10;
		ndigits++;
	}
	return (ndigits);
}

/*
	DESCRIPTION
	Allocates memory and returns a string representing the
	integer received as an argument. Negative numbers are
	handle.

	RETURN
	A pointer to the string representing the number.
	NULL if allocation fails.
*/
char	*ft_itoa(int n)
{
	char	*str;
	int		ndigits;
	int		stop;
	long	num;

	num = n;
	stop = 0;
	ndigits = ft_num_of_digits(n);
	str = (char *)malloc((ndigits + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (num < 0)
	{
		num *= -1;
		stop = 1;
		str[0] = '-';
	}
	str[ndigits] = 0;
	while (ndigits-- > stop)
	{
		str[ndigits] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
