#include <unistd.h>
extern int	g_puzzle[4][4];
int	verify_row_col(int line, int column);
int	verify_col_up(int y, int rules[4][4]);
int	verify_col_down(int y, int rules[4][4]);
int	verify_row_left(int x, int rules[4][4]);
int	verify_row_right(int x, int rules[4][4]);

int	verify_guess(int guess, int x, int y, int rules[4][4])
{
	g_puzzle[x][y] = guess;
	if (verify_row_col(x, y))
		if (verify_col_up(y, rules))
			if (verify_col_down(y, rules))
				if (verify_row_left(x, rules))
					if (verify_row_right(x, rules))
						return (1);
	g_puzzle[x][y] = 0;
	return (0);
}

int	solve(int x, int y, int rules[4][4])
{
	int	guess;

	guess = 1;
	while (guess < 5)
	{
		if (verify_guess(guess, x, y, rules))
		{
			if (y != 3)
			{
				if (solve(x, y + 1, rules))
					return (1);
			}
			else
			{
				if (x != 3)
					if (solve(x + 1, 0, rules))
						return (1);
			}
			if (y == 3 && x == 3)
				return (1);
		}
		guess++;
	}
	g_puzzle[x][y] = 0;
	return (0);
}

int	print_puzzle(int x)
{
	int	y;
	int	c;

	if (x == 1)
	{
		x = 0;
		while (x < 4)
		{
			y = 0;
			while (y < 4)
			{
				c = g_puzzle[x][y] + '0';
				write(1, &c, 1);
				if (y == 3)
					write(1, "\n", 1);
				else
					write(1, " ", 1);
				y++;
			}
			x++;
		}
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
