/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carda-si <carda-si@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 01:15:35 by carda-si          #+#    #+#             */
/*   Updated: 2021/06/12 14:45:09 by carda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_alpha(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	else if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

char	ft_upcase(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 32);
	}
	else
	{
		return (c);
	}
}

char	ft_lowcase(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + 32);
	}
	else
	{
		return (c);
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	str[0] = ft_upcase(str[0]);
	while (str[i] != '\0')
	{
		if (!ft_alpha(str[i - 1]) && ft_alpha(str[i]))
		{
			str[i] = ft_upcase(str[i]);
		}
		else
		{
			str[i] = ft_lowcase(str[i]);
		}
		i++;
	}
	return (str);
}
