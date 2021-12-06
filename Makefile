CC = gcc
FLAGS = -Wall -Wextra -Werror

all: clean
	make -C ../get_next_line/libft/ fclean && make -C ../get_next_line/libft/
	make main && make main1 && make main2
	
main:
	$(CC) $(FLAGS) -I ../get_next_line/libft/includes -o ../get_next_line/get_next_line.o -c ../get_next_line/get_next_line.c
	$(CC) $(FLAGS) -I ../get_next_line/libft/includes -o main.o -c main.c
	clang -o main.out main.o ../get_next_line/get_next_line.o -I ../get_next_line/libft/includes -L ../get_next_line/libft/ -lft
#	../get_next_line/*.c ../get_next_line/*.h *.c *.h ../get_next_line/libft/*.c ../get_next_line/libft/*.h

main1:
	$(CC) $(FLAGS) -I ../get_next_line/libft/includes -o ../get_next_line/get_next_line.o -c ../get_next_line/get_next_line.c
	$(CC) $(FLAGS) -I ../get_next_line/libft/includes -o main1.o -c main1.c
	clang -o main1.out main1.o ../get_next_line/get_next_line.o -I ../get_next_line/libft/includes -L ../get_next_line/libft/ -lft

main2:
	$(CC) $(FLAGS) -I ../get_next_line/libft/includes -o ../get_next_line/get_next_line.o -c ../get_next_line/get_next_line.c
	$(CC) $(FLAGS) -I ../get_next_line/libft/includes -o main2.o -c main2.c
	clang -o main2.out main2.o ../get_next_line/get_next_line.o -I ../get_next_line/libft/includes -L ../get_next_line/libft/ -lft

clean:
	rm -f ../get_next_line/libft/*.o ../get_next_line/libft/*.a *.gch *.o *.out ../get_next_line/*.o

fclean: clean
	rm -rf

re: fclean all
