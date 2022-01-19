#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    char *line = NULL;
    int fd = open(argv[1], O_RDONLY);

    int lines = 0;
    size_t bytes;

	if (argc != 2)
		return (0);
    double timer = 0;
    while (1)
    {
        clock_t begin = clock();
        bytes = get_next_line(fd, &line);
        clock_t end = clock();
        timer += (double)(end - begin) / CLOCKS_PER_SEC;
        if (bytes <= 0)
        {
            break;
        }
        write(STDOUT_FILENO, line, bytes);
        write(STDOUT_FILENO, "\n", 1);
        free(line);
        ++lines;
    }

    //free(line);
    printf("\nTotal lines: %d, Total time: %f\n", lines, timer);
}