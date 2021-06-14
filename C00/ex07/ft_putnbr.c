/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carda-si <carda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 04:36:52 by carda-si          #+#    #+#             */
/*   Updated: 2021/06/08 20:16:13 by carda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int num)
{
	num = num + '0';
	write(1, &num, 1);
}

int	expo(int base, int exponent)
{
	int	accumulator;
	int	i;

	accumulator = 1;
	i = 0;
	while (i < exponent)
	{
		accumulator *= base;
		i++;
	}
	return (accumulator);
}

void	ft_convert_int_to_char(int nb)
{
	int	number_digits;
	int	quotient;
	int	i;
	int	number;
	int	a;

	number_digits = 0;
	quotient = nb;
	i = 0;
	a = nb;
	while (quotient != 0)
	{
		quotient = quotient / 10;
		number_digits++;
	}
	while (i < number_digits)
	{
		number = (a / (expo(10, number_digits - 1) / expo(10, i)));
		ft_putchar(number);
		i++;
		a = nb % expo(10, i);
	}
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
	{
		write (1, "0", 1);
	}
	else if (nb < 0)
	{
		write (1, "-", 1);
		nb *= -1;
		ft_convert_int_to_char (nb);
	}
	else
	{
		ft_convert_int_to_char (nb);
	}
}
