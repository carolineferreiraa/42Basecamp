extern int	g_puzzle[4][4];

int	verify_row_col(int line, int column)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (g_puzzle[line][i] == g_puzzle[line][column] && (column != i))
			return (0);
		if (g_puzzle[i][column] == g_puzzle[line][column] && (line != i))
			return (0);
		++i;
	}
	return (1);
}

int	verify_col_up(int y, int rules[4][4])
{
	int	count;
	int	aux;
	int	current;

	count = 1;
	aux = 0;
	current = g_puzzle[0][y];
	while (aux != 4)
	{
		if (g_puzzle[aux][y] == 0)
			return (1);
		if (current < g_puzzle[aux][y])
		{
			count++;
			current = g_puzzle[aux][y];
		}
		aux++;
	}
	if (rules[0][y] == count)
		return (1);
	else
		return (0);
}

int	verify_col_down(int y, int rules[4][4])
{
	int	count;
	int	aux;
	int	current;

	count = 1;
	aux = 3;
	current = g_puzzle[3][y];
	while (aux >= 0)
	{
		if (g_puzzle[aux][y] == 0)
			return (1);
		if (current < g_puzzle[aux][y])
		{
			count++;
			current = g_puzzle[aux][y];
		}
		aux--;
	}
	if (rules[1][y] == count)
		return (1);
	else
		return (0);
}

int	verify_row_left(int x, int rules[4][4])
{
	int	count;
	int	aux;
	int	current;

	count = 1;
	aux = 0;
	current = g_puzzle[x][0];
	while (aux != 4)
	{
		if (g_puzzle[x][aux] == 0)
			return (1);
		if (current < g_puzzle[x][aux])
		{
			count++;
			current = g_puzzle[x][aux];
		}
		aux++;
	}
	if (rules[2][x] == count)
		return (1);
	else
		return (0);
}

int	verify_row_right(int x, int rules[4][4])
{
	int	count;
	int	aux;
	int	current;

	count = 1;
	aux = 3;
	current = g_puzzle[x][3];
	while (aux >= 0)
	{
		if (g_puzzle[x][aux] == 0)
			return (1);
		if (current < g_puzzle[x][aux])
		{	
			count++;
			current = g_puzzle[x][aux];
		}
		aux--;
	}
	if (rules[3][x] == count)
		return (1);
	else
		return (0);
}
