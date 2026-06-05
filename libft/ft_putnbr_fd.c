/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 08:49:43 by czuluaga          #+#    #+#             */
/*   Updated: 2026/04/27 11:52:55 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_power(unsigned int n)
{
	int	pow;

	pow = 0;
	while (n / 10 != 0)
	{
		n /= 10;
		pow++;
	}
	return (pow);
}

static unsigned int	ft_pow(int base, int pow)
{
	unsigned int	num;

	if (!pow)
		return (1);
	num = 1;
	while (pow--)
		num *= base;
	return (num);
}

/*
	DESCRIPTION
	Outputs the integer 'n' to the specified file descriptor fd.
*/
void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;
	int				pow;
	unsigned int	tpow;

	num = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num = (-1 * n);
	}
	pow = ft_get_power(num);
	while (pow >= 0)
	{
		tpow = ft_pow(10, pow);
		ft_putchar_fd('0' + (num / tpow), fd);
		num %= tpow;
		pow--;
	}
}
