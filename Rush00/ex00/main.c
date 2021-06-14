#include <stdio.h>
#include <unistd.h>

void	rush00(int x, int y);
void	rush01(int x, int y);
void	rush02(int x, int y);
void	rush03(int x, int y);
void	rush04(int x, int y);
void	ft_putchar(char c);

void	rush(int x, int y)
{
	write(1, "Rush00:", 8);
	ft_putchar('\n');
	rush00(x, y);
	write(1, "Rush01:", 8);
	ft_putchar('\n');
	rush01(x, y);
	write(1, "Rush02:", 8);
	ft_putchar('\n');
	rush02(x, y);
	write(1, "Rush03:", 8);
	ft_putchar('\n');
	rush03(x, y);
	write(1, "Rush04:", 8);
	ft_putchar('\n');
	rush04(x, y);
}

int	parse_int(char *str)
{
	int	num;
	int	i;

	num = 0;
	i = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);
}

int	test_args_for_negative(char *str_1, char *str_2)
{
	int	is_negative;

	if (str_1[0] == '-' || str_2[0] == '-')
	{
		is_negative = 0;
		return (is_negative);
	}
	is_negative = 1;
	return (is_negative);
}

int	check_args(int	args)
{
	int	has_args;

	if (args < 3)
	{
		write(1, "Missing X or Y value!", 21);
		ft_putchar('\n');
		has_args = 0;
		return (has_args);
	}
	else if (args > 3)
	{
		write(1, "Max arguments number is 2!", 26);
		ft_putchar('\n');
		has_args = 0;
		return (has_args);
	}
	else
	{
		has_args = 1;
		return (has_args);
	}
}

int	main(int argc, char **argv)
{
	int	x;
	int	y;
	int	is_negative;

	if (!check_args(argc))
	{
		return (0);
	}
	is_negative = test_args_for_negative(argv[1], argv[2]);
	if (!is_negative)
	{
		write(1, "Negative numbers aren't accepted!", 33);
		ft_putchar('\n');
		return (0);
	}
	x = parse_int(argv[1]);
	y = parse_int(argv[2]);
	rush(x, y);
	return (0);
}
