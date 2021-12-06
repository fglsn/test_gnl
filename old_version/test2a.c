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

	FILE *fileptr = fopen(filename, "r");

	ssize_t res2;

	char *line2 = NULL;

	size_t n = 32;

	int nline = 0;

	res2 = getline(&line2, &n, fileptr);
	while (res2 > 0)
	{
		nline++;
		if (nline % 1000 == 0)
		{
			printf("Read line n.%d\n", nline);
		}
		char *ptr_to_n = strrchr(line2, '\n');
		if (ptr_to_n)
			*ptr_to_n = '\0';
		res2 = getline(&line2, &n, fileptr);
	}
	if (res2 != -1)
	{
		printf("getline() return value: %zd", res2);
		return (1);
	}
	printf("OK! All lines read with get_new_line\n");
	return (0);
}