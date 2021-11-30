#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void text_gen(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("1st argument is number of lines;\n3rd arg is filename (with .txt).\n");
		return ;
	}
	int lines = atoi(argv[1]);
	int line_length;
	char *file = argv[2];
	FILE *fptr;
	fptr = fopen(file, "w");
	char letter = 'A';
	while (lines > 0)
	{
		line_length = lines * 10;
		while (line_length > 0)
		{
			fprintf(fptr, "%c", letter);
			line_length--;
		}
		letter++;
		fprintf(fptr, "\n");
		lines--;
	}
	fclose(fptr);
	return ;
}

int main(int argc, char **argv)
{
	text_gen(argc, argv);
	char *filename = argv[2];
	int fd;
	char *result;
	fd = open(filename, O_RDONLY);

	get_next_line(fd, &result);
	printf("%s\n", result);
	get_next_line(fd, &result);
	printf("%s\n", result);
	get_next_line(fd, &result);
	printf("%s\n", result);
	get_next_line(fd, &result);
	printf("%s\n", result);
	get_next_line(fd, &result);
	printf("%s\n", result);
	
	return (1);
}