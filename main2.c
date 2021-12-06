#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Missing filename\n");
		return (1);
	}
	char *filename = argv[1];

	int fd1 = open(filename, O_RDONLY);
	FILE *fileptr = fopen(filename, "r");

	ssize_t res1;
	ssize_t res2;

	char *line1;
	char *line2 = NULL;

	size_t n = 32;

	int nline = 0;

	res1 = get_next_line(fd1, &line1);
	res2 = getline(&line2, &n, fileptr);
	while (res1 > 0 && res2 > 0)
	{
		nline++;
		if (nline % 1000 == 0)
		{
			printf("Read line n.%d\n", nline);
		}
		char *ptr_to_n = strrchr(line2, '\n');
		if (ptr_to_n)
			*ptr_to_n = '\0';
		if (strcmp(line1, line2))
		{
			printf("Error! Your function reads line: '%s'. Return value: %zd\nGetline result on same line: '%s'. Return value: %zd\n", line1, res1, line2, res2);
			return (1);
		}
		res1 = get_next_line(fd1, &line1);
		res2 = getline(&line2, &n, fileptr);
	}
	if (res1 != 0 || res2 != -1)
	{
		printf("Error! Gnl() return value: %zd and getline() return value: %zd (Should be 0 and -1 respectively\n", res1, res2);
		return (1);
	}
	printf("OK! All lines read with get_new_line\n");
	return (0);
}