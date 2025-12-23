*This project has been created as part of the 42 curriculum by kel-ger*

## Description

This project consists of creating a function called `get_next_line` that reads a string line by line from a file descriptor. This function has 
to be called repeatedly. A key feature of this project is the use of static variables which allows data to be preserved between two 
successive calls. Furthermore, strict memory management is required to ensure that all memory leaks are avoided. The function returns line 
that was read by including `\n`, and return `NULL`, if there is nothing else to read or if an error occurs.

## Instructions

### Compilation
To compile the code, create a main.c file and also a  :

This is an example of a main.c 
```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"
int main(void)
{
	int fd = open("tst.txt", O_RDONLY);
	char	*line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return(0);
}

```
and the file tst.txt contains ; 
hello
you

The expected output is :
hello
you

# Resources


## Algorithms and data structures


