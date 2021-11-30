CC = gcc
FLAGS = -Wall -Wextra -Werror

all: clean
	make -C ../get_next_line/libft/ fclean && make -C ../get_next_line/libft/
	make f
	
f:
	$(CC) $(FLAGS) -I ../get_next_line/libft/includes -o ../get_next_line/get_next_line.o -c ../get_next_line/get_next_line.c
	$(CC) $(FLAGS) -I ../get_next_line/libft/includes -o main.o -c main.c
	clang -o a.out main.o ../get_next_line/get_next_line.o -I ../get_next_line/libft/includes -L ../get_next_line/libft/ -lft
#	../get_next_line/*.c ../get_next_line/*.h *.c *.h ../get_next_line/libft/*.c ../get_next_line/libft/*.h

clean:
	rm -f ../get_next_line/libft/*.o ../get_next_line/libft/*.a *.gch *.o *.out ../get_next_line/*.o

fclean: clean
	rm -rf

re: fclean all
