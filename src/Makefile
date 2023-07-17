CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: s21_math_test

s21_math_test: s21_math.c s21_math_test.c 
	$(CC) $(CFLAGS) -o s21_math_test s21_math_test.c -lcheck -lm
	./s21_math_test

clean:
	rm -f s21_math_test

.PHONY: all clean