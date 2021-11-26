#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	char buffer[BUFF_SIZE];
	char *filename = "test.txt";
	int fd;
	ssize_t result;

	fd = open(filename, O_RDONLY);

	result = read(fd, buffer, BUFF_SIZE);
	printf("%zu\n", result);
	return (1);
}