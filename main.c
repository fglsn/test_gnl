#include "../get_next_line/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char **text_gen(int argc, char **argv)
{
	int		i = 0;
	int		j = 1;
	int		line_length;
	int		lines = argc - 1;
	char	letter = 'A';

	char **result;
	result = (char **)malloc(sizeof(char *) * (lines + 1));
	if (!result)
		return (NULL);
	ft_bzero(result, sizeof(char *) * (lines + 1));

	while (lines != 0)
	{
		line_length = atoi(argv[j]);
		result[i] = ft_strnew(line_length);
		if (!result[i])
			return (NULL);
		ft_memset(result[i], letter, line_length);
		i++;
		j++;
		letter++;
		lines--;
	}
	return (result);
}

void file_gen(char **text, char *filename)
{
	FILE *fptr;
	fptr = fopen(filename, "w");
	while (*text)
	{
		fprintf(fptr, "%s\n", *text);
		text++;
	}
	fclose(fptr);
	return ;
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Provide at least one linelength.\n");
		return (1);
	}
	char **text = text_gen(argc, argv);
	char *filename = "txt.txt";
	file_gen(text, filename);
	int fd;
	char *result;
	int res;
	int failed = 0;
	int count_lines = 0;
	fd = open(filename, O_RDONLY);
	//fd = 1;
	while (*text)
	{
		res = get_next_line(fd, &result);
		if (res == 1 && !strcmp(result, *text))
		{
			//printf("%s vs. %s\n", result, *text);
			//printf("Line OK\n");
			count_lines++;
		}
		else {
			printf("Failed, expected '%s', got '%s'\n", *text, result);
			failed++;
		}
		text++;
	}
	if (!failed && (res = get_next_line(fd, &result)) == 0)
		printf("OK: Everything read\nLines read before 0 was returned: %d\n", count_lines);
	else if (!failed)
		printf("KO!\nResult line -%s-\nRes value: %d\n", result, res);
	return (0);
}