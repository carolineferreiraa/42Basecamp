#include <unistd.h>
void	ft_putchar(char c);

void	write_lines(int write_x, int x, char chars_list[])
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

void	draw_columns(int write_y, int write_x, int y, int x)
{
	char	chars_list_first_line[3];
	char	chars_list_middle_lines[3];
	char	chars_list_last_line[3];

	chars_list_first_line[0] = '/';
	chars_list_first_line[1] = '*';
	chars_list_first_line[2] = '\\';
	chars_list_middle_lines[0] = '*';
	chars_list_middle_lines[1] = ' ';
	chars_list_middle_lines[2] = '*';
	chars_list_last_line[0] = '\\';
	chars_list_last_line[1] = '*';
	chars_list_last_line[2] = '/';
	if (write_y == 1)
	{
		write_lines(write_x, x, chars_list_first_line);
	}
	else if (write_y > 1 && write_y < y)
	{
		write_lines(write_x, x, chars_list_middle_lines);
	}
	else
	{
		write_lines(write_x, x, chars_list_last_line);
	}
}

void	draw_pattern(int x, int y, int write_y, int write_x)
{
	while (write_y <= y)
	{
		write_x = 1;
		while (write_x <= x)
		{
			draw_columns(write_y, write_x, y, x);
			write_x++;
		}
		write_y++;
	}
}

void	rush01(int x, int y)
{
	int	write_x;
	int	write_y;

	write_y = 1;
	write_x = 1;
	draw_pattern(x, y, write_y, write_x);
}
