#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void test1()
{
	char *line;
	int result;
	int i = 0;
	int count_lines = 0;
	int fd = open("test.txt", O_RDONLY);
	char *text_lines[5] = {
		"ABCDEFGHIJKLMNO",
		"1234567890",
		"test",
		"with a",
		"text and without new line at the end"
	};
	printf("\nTest 1: \n");
	printf("-----------------\n");
	while (i != 5)
	{
		result = get_next_line(fd, &line);
		if (result == 1 && !strcmp(text_lines[i], line))
		{
			printf("%s vs. %s\n", text_lines[i], line);
			//printf("Line ok\n");
			count_lines++;
		}
		else {
			printf("Failed, expected '%s', got '%s'\nExpected return value: 1, got %d\n", text_lines[i], line, result);
			printf("-----------------\n");
			exit(-1);
		}
		i++;
	}
	if ((result = get_next_line(fd, &line)) == 0 && count_lines == 5)
		printf("\nOK: Everything read\nOne returned %d times\n", count_lines);
	close(fd);
	printf("-----------------\n");
}

void test2()
{
	char *line;
	int result;
	int fd = open("test2.txt", O_RDONLY);
	printf("\nTest 2: \n");
	printf("-----------------\n");
	if ((result = get_next_line(fd, &line)) == 0)
		printf("OK: returned only 0\n");
	else
		printf("Should've returned only 0, but returned %d\n", result);
	printf("-----------------\n");
}

void test3()
{
	char *line;
	int fd1 = open("test.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);
	int fd3 = open("test3.txt", O_RDONLY);

	int res1;
	int res2;
	int res3;

	printf("\nTest 3: \n");
	printf("-----------------\n");
	res1 = get_next_line(fd1, &line);
	if (res1 == 1 && !strcmp("ABCDEFGHIJKLMNO", line))
	{
		printf("Fd1 line1: %s\n", line);
		printf("OK: Line 1 from test.txt\n\n");
	}
	else {
		printf("Failed, expected 'ABCDEFGHIJKLMNO', got '%s'\nExpected return value: 1, got %d\n\n", line, res1);
		printf("-----------------\n");
		exit(-1);
	}

	if ((res2 = get_next_line(fd2, &line)) == 0)
	{
		printf("Fd2 is empty\n");
		printf("OK: returned only 0, test1.txt\n\n");
	}
	else
		printf("Should've returned only 0, but returned %d\n\n", res2);

	res1 = get_next_line(fd1, &line);
	if (res1 == 1 && !strcmp("1234567890", line))
		{
			printf("Fd1 line2: %s\n", line);
			printf("OK: Line 2 from test.txt\n\n");
		}
		else {
			printf("Failed, expected '1234567890', got '%s'\nExpected return value: 1, got %d\n\n", line, res1);
			printf("-----------------\n");
			exit(-1);
		}

	res3 = get_next_line(fd3, &line);
	if (res3 == 1 && !strcmp("Hello, let's check", line))
		{
			printf("Fd3 line1: %s\n", line);
			printf("OK: Line 1 from test3.txt\n\n");
		}
		else {
			printf("Failed, expected 'Hello, let's check', got '%s'\nExpected return value: 1, got %d\n\n", line, res3);
			printf("-----------------\n");
			exit(-1);
		}

	res1 = get_next_line(fd1, &line);
	if (res1 == 1 && !strcmp("test", line))
		{
			printf("Fd1 line3: %s\n", line);
			printf("OK: Line 3 from test.txt\n\n");
		}
		else {
			printf("Failed, expected 'test', got '%s'\nExpected return value: 1, got %d\n\n", line, res1);
			printf("-----------------\n");
			exit(-1);
		}

	res3 = get_next_line(fd3, &line);
	if (res3 == 1 && !strcmp("line2", line))
		{
			printf("Fd3 line2: %s\n", line);
			printf("OK: Line 2 from test3.txt\n\n");
		}
		else {
			printf("Failed, expected 'line2', got '%s'\nExpected return value: 1, got %d\n\n", line, res3);
			printf("-----------------\n");
			exit(-1);
		}
	printf("\nMultiple file descriptors OK \n");
	printf("-----------------\n");
}

int main(void)
{
	test1();
	test2();
	test3();
	return (0);
}