#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(char hundred, char ten, char unity)
{
	if (hundred == ten || ten == unity || hundred == unity)
	{
	}
	else if (hundred == '7' && ten == '8' && unity == '9')
	{
		ft_putchar(hundred);
		ft_putchar(ten);
		ft_putchar(unity);
	}
	else if (unity > ten && unity > hundred && ten > hundred)
	{
		ft_putchar(hundred);
		ft_putchar(ten);
		ft_putchar(unity);
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_print_comb(void)
{
	char	hundred;
	char	ten;
	char	unity;

	hundred = '0';
	ten = '0';
	unity = '0';
	while (hundred <= '9' && ten <= '9' && unity <= '9')
	{
		ft_print(hundred, ten, unity);
		if (unity >= '9')
		{
			unity = '0';
			ten++;
		}
		if (ten >= '9')
		{
			unity = '0';
			ten = '0';
			hundred++;
		}
		unity++;
	}
}

int	 main(void)
{
	ft_print_comb();
}
