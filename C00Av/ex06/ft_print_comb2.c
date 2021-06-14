#include <unistd.h>

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

void	ft_condition(int numb1, int numb2)
{		
	if (numb1 == 98 && numb2 == 99)
	{
		ft_putnbr_positive(numb1);
		write(1, " ", 1);
		ft_putnbr_positive(numb2);
	}
	else if (numb1 < numb2)
	{
		if (numb1 < 10)
		{
			write(1, "0", 1);
			ft_putnbr_positive(numb1);
		}
		else
			ft_putnbr_positive(numb1);
		write(1, " ", 1);
		if (numb2 < 10)
		{
			write(1, "0", 1);
			ft_putnbr_positive(numb2);
		}
		else
			ft_putnbr_positive(numb2);
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int	numb1;
	int	numb2;

	numb1 = 0;
	numb2 = 0;
	while (numb1 <= 99)
	{
		numb2 = 0;
		while (numb2 <= 99)
		{
			ft_condition(numb1, numb2);
			numb2++;
		}
		numb1++;
	}
}

int main(void)
{
	ft_print_comb2();
}