*This project has been created as part of the 42 curriculum by \<kel-ger\>*

## Description

This project consists of creating a function called `get_next_line` that reads a string line by line from a file descriptor. This function has 
to be called repeatedly. A key feature of this project is the use of static variables which allows data to be preserved between two 
successive calls. Furthermore, strict memory management is required to ensure that all memory leaks are avoided. The function returns line 
that was read by including `\n`, and return `NULL`, if there is nothing else to read or if an error occurs.

## ⚙️ Instructions
### Compilation
The code is compiled using the following command.
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=n get_next_line.c get_next_line_utils.c main.c
```
 where n is a given value.
 Note : `*.c` may be used if the directory only contains the relevant project files.
 ```bash
 cc -Wall -Wextra -Werror -D BUFFER_SIZE=n *.c
```
### Usage Example
The following main.c serves as an example to test the 
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
With a test file named `tst.txt` containing:

**tst.txt:**
```text
hello
you
```
The expected output is :
```text
hello
you
```
## 📚 Resources
### Static Variables
One of the goals of this project was the discovery and implementation of static variables.
The following resources were consulted to clarify the concept.

- [GeeksforGeeks - Static Variables](https://www.geeksforgeeks.org/c/static-variables-in-c/)
- [Codequoi - Variables en C](https://www.codequoi.com/variables-locales-globales-statiques-en-c/)
- [Video Tutorial - Static Variables](https://www.youtube.com/watch?v=Hm5Jc7ajZsk)

### AI Usage
AI was employed like an educational tool to clarify concepts and to assist with debugging the code.

## 🧠 Algorithms
The Algorithm consists of several key steps :

- Initialization : The process start with the static variable set to `NULL`.
- Reading and Storage : A buffer of size `BUFFER_SIZE` is allocated dynamically. The data is read and is stored in the static variable until the first occurrence of `\n` appears , or the end of the file is reached.
- Extraction : The line is extracted from the static variable when `\n` appears.
- Remainder management : The content remaining after `\n` is isolated and saved back into the static variable.

  

