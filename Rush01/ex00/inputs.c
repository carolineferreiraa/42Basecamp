int	input_to_int(char *argv, int rules[4][4])
{
	int	x;
	int	y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (*argv < '1' || *argv > '4')
				return (0);
			if (*(argv + 1) == ' ' || (x == 3 && y == 3))
				rules[x][y] = *argv - '0';
			else
				return (0);
			argv = argv + 2;
			y++;
		}
		x++;
	}
	if (*(argv - 1) == '\0')
		return (1);
	return (0);
}

int	initialize_matrix(int matrix[4][4])
{
	int	x;
	int	y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			matrix[x][y] = 0;
			y++;
		}
		x++;
	}
	return (0);
}
