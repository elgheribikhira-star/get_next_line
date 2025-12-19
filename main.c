
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int fd = open("tst.txt", O_RDONLY);
	char	*line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
}

