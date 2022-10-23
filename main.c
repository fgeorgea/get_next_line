#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
int	main(void)
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
}
