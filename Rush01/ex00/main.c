#include <unistd.h>
int	solve(int x, int y, int rules[4][4]);
int	input_to_int(char *argv, int rules[4][4]);
int	print_puzzle(int x);
int	initialize_matrix(int matrix[4][4]);

int	g_puzzle[4][4];

int	main(int argc, char *argv[])
{
	int	rules[4][4];

	if (argc != 2 || !(input_to_int(argv[1], rules)))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	initialize_matrix(g_puzzle);
	print_puzzle(solve(0, 0, rules));
}
