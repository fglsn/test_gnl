CC = gcc
FLAGS = -Wall -Wextra -Werror

all: clean
	$(CC) $(FLAGS) ../get_next_line/*.c ../get_next_line/*.h *.c *h

clean:
	rm -f *.o *.gch ./a.out ../get_next_line/*.gch

fclean: clean
	rm -rf

re: fclean all
