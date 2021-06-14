/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carda-si <carda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 03:51:38 by carda-si          #+#    #+#             */
/*   Updated: 2021/06/09 00:21:50 by carda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char num[3])
{
	if (num[0] == '7' && num[1] == '8' && num[2] == '9')
	{
		write(1, num, 3);
	}
	else
	{
		write(1, num, 3);
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char	num[3];

	num[0] = '0';
	num[1] = '1';
	num[2] = '2';
	while (num[0] <= '7')
	{
		while (num[1] <= '8')
		{
			while (num[2] <= '9')
			{
				ft_putchar(num);
				++num[2];
			}
			num[2] = ++num[1] + 1;
		}
		num[1] = ++num[0] + 1;
		num[2] = num[1] + 1;
	}
}
