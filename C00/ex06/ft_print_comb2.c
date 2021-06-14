/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carda-si <carda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 04:05:56 by carda-si          #+#    #+#             */
/*   Updated: 2021/06/09 00:22:03 by carda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar (char	num[5])
{
	if (num[0] == '9' && num[1] == '8' && num[3] == '9' && num[4] == '9')
	{
		write(1, num, 5);
	}
	else
	{
		write(1, num, 5);
		write(1, ", ", 2);
	}
}

void	ft_calculate_second_number(char	num[5])
{
	while (num[3] <= '9')
	{
		while (num[4] <= '9')
		{
			ft_putchar(num);
			++num[4];
		}
		++num[3];
		num[4] = '0';
	}
}

void	ft_print_comb2(void)
{
	char	num[5];

	num[0] = '0';
	num[1] = '0';
	num[2] = ' ';
	num[3] = '0';
	num[4] = '1';
	while (num[0] <= '9')
	{
		while (num[1] <= '9')
		{
			ft_calculate_second_number(num);
			num[3] = num[0];
			num[4] = ++num[1] + 1;
		}
		num[1] = '0';
		num[3] = ++num[0];
		num[4] = '1';
	}
}
