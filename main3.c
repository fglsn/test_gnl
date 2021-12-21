#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"


int main(void)
{
	//int i = open("txt.txt", O_RDONLY);

	char* line;

	int res = get_next_line(0, &line);
	ft_putendl(line);
	printf("%d\n", res);
}
