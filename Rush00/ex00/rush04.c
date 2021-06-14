#include <unistd.h>
void	ft_putchar(char c);

void	write_lines_rush04(int write_x, int x, char chars_list[])
{
	if (write_x == 1)
	{
		ft_putchar(chars_list[0]);
		if (write_x == x)
		{
			ft_putchar('\n');
		}
	}
	else if (write_x > 1 && write_x < x)
	{
		ft_putchar(chars_list[1]);
	}
	else
	{
		ft_putchar(chars_list[2]);
		ft_putchar('\n');
	}
}

void	draw_columns_rush04(int write_y, int write_x, int y, int x)
{
	char	chars_list_first_line[3];
	char	chars_list_middle_lines[3];
	char	chars_list_last_line[3];

	chars_list_first_line[0] = 'A';
	chars_list_first_line[1] = 'B';
	chars_list_first_line[2] = 'C';
	chars_list_middle_lines[0] = 'B';
	chars_list_middle_lines[1] = ' ';
	chars_list_middle_lines[2] = 'B';
	chars_list_last_line[0] = 'C';
	chars_list_last_line[1] = 'B';
	chars_list_last_line[2] = 'A';
	if (write_y == 1)
	{
		write_lines_rush04(write_x, x, chars_list_first_line);
	}
	else if (write_y > 1 && write_y < y)
	{
		write_lines_rush04(write_x, x, chars_list_middle_lines);
	}
	else
	{
		write_lines_rush04(write_x, x, chars_list_last_line);
	}
}

void	draw_pattern_rush04(int x, int y, int write_y, int write_x)
{
	while (write_y <= y)
	{
		write_x = 1;
		while (write_x <= x)
		{
			draw_columns_rush04(write_y, write_x, y, x);
			write_x++;
		}
		write_y++;
	}
}

void	rush04(int x, int y)
{
	int	write_x;
	int	write_y;

	write_y = 1;
	write_x = 1;
	draw_pattern_rush04(x, y, write_y, write_x);
}
