#include <unistd.h>

int	ft_pow (int base, int expo)
{
	if (expo == 0)
	{
		return (1);
	}
	else if (expo > 0)
	{
		return (base * ft_pow (base, expo - 1));
	}
	else
	{
		return (1 / ft_pow (base, -expo));
	}
}

void	ft_putnbr_positive(int nb)
{
	char	c;

	if (nb < 10)
	{
		c = nb + 48;
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr_positive(nb / 10);
		ft_putnbr_positive(nb % 10);
	}
}

int	ft_calculate_0(int current, int n)
{
	int	n_pow;
	int	number_of_0;

	if (n == 1)
	{
		return (0);
	}
	n_pow = ft_pow(10, n - 1);
	number_of_0 = 0;
	while (current < n_pow)
	{
		number_of_0++;
		n_pow = n_pow / 10;
	}
	return (number_of_0);
}

int	ft_verifica(int current, int current_print, int num_0, int *first)
{
	int	num_1;
	int	num_2;

	while (current >= 0)
	{
		if (current == 0)
			break ;
		num_1 = current % 10;
		num_2 = current / 10;
		num_2 = num_2 % 10;
		if (num_2 >= num_1)
			return (1);
		else
			current = current / 10;
	}
	if (*first)
		write(1, ", ", 2);
	while (num_0 > 0)
	{
		ft_putnbr_positive(0);
		num_0--;
	}
	*first = 1;
	ft_putnbr_positive(current_print);
	return (0);
}

void	ft_print_combn(int n)
{
	int	current;
	int	number_of_0;
	int	max;
	int	first;

	if (n == 1)
		current = 0;
	else
		current = 1;
	max = ft_pow(10, n) - 1;
	first = 0;
	while (current <= max && current <= 123456789)
	{
		number_of_0 = ft_calculate_0(current, n);
		if ((number_of_0 == 0 || number_of_0 == 1))
		{
			ft_verifica(current, current, number_of_0, &first);
		}		
		if (current == 23456789)
			current = 123456788;
		current++;
	}
}
