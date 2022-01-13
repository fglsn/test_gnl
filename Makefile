CC = clang
FLAGS = -Wall -Wextra -Werror

all: clean
	make -C ../get_next_line/libft/ fclean && make -C ../get_next_line/libft/
	make main && make main1 && make main2 && make main3
	
main:
	$(CC) $(FLAGS) -I ../get_next_line/libft/includes -o ../get_next_line/get_next_line.o -c ../get_next_line/get_next_line.c
	$(CC) $(FLAGS) -I ../get_next_line/libft/includes -o main.o -c main.c
	clang -o main main.o ../get_next_line/get_next_line.o -I ../get_next_line/libft/includes -L ../get_next_line/libft/ -lft
#	../get_next_line/*.c ../get_next_line/*.h *.c *.h ../get_next_line/libft/*.c ../get_next_line/libft/*.h

main1:
	$(CC) $(FLAGS) -I ../get_next_line/libft/includes -o ../get_next_line/get_next_line.o -c ../get_next_line/get_next_line.c
	$(CC) $(FLAGS) -I ../get_next_line/libft/includes -o main1.o -c main1.c
	clang -o main1 main1.o ../get_next_line/get_next_line.o -I ../get_next_line/libft/includes -L ../get_next_line/libft/ -lft

main2:
	$(CC) $(FLAGS) -I ../get_next_line/libft/includes -o ../get_next_line/get_next_line.o -c ../get_next_line/get_next_line.c
	$(CC) $(FLAGS) -I ../get_next_line/libft/includes -o main2.o -c main2.c
	clang -o main2 main2.o ../get_next_line/get_next_line.o -I ../get_next_line/libft -L ../get_next_line/libft/ -lft

main3:
	$(CC) $(FLAGS) -I ../get_next_line/libft/includes -o ../get_next_line/get_next_line.o -c ../get_next_line/get_next_line.c
	$(CC) $(FLAGS) -I ../get_next_line/libft/includes -o main3.o -c main3.c
	clang -o main3 main3.o ../get_next_line/get_next_line.o -I ../get_next_line/libft -L ../get_next_line/libft/ -lft

test: clean
	./main 0 1 2 3 4 5 6 7 8 9 15000 30000 50000 100000 1000000
	./main1 test
	./main2	file
	./main2	file1
	./main2	file2
	./main2	test_bible
	./main2	test1
	./main2	test2
	./main2	txt.txt
	./main3

clean:
	rm -f ../get_next_line/libft/*.o ../get_next_line/libft/*.a *.gch *.o *.out ../get_next_line/*.o

fclean: clean
	rm -rf main main1 main2 main3

re: fclean all
