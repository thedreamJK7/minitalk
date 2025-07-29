#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc < 2)
    {
		write(2, "Usage: ./a.out <char>\n", 23);
        return (1);
    }
	unsigned char bit = 0;
	unsigned char octet = argv[1][0];
	int i = 8;

	printf("%c\n", octet);
	while (i--)
	{
		bit = ((octet >> i) & 1) + 48;
		write(1, &bit, 1);
	}
	return (0);
}

