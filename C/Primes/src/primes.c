/*
 * @auther Stephen Cochrane
 * Feel free to use/ critique
 * a prime factor list is built to use for all calculations 
   (Sieve of Eratosthenes) :D
 * */
#include <stdlib.h>
#include <stdio.h>

typedef struct pair {
	int number;
	int is_checked;
} pair;

pair *create_prime_list(int max);
void show_primes(pair *arr, int start, int end);
int is_prime(int prime);
void prime_factor(int num);

int main ()
{
	int mode, num, i, j;

	printf("Usage\n0: Test if a number is prime\n");
	printf("1: Generate a list of prime numbers from i-j\n");
	printf("2: Find a numbers prime factorisation\n");
	printf("Enter mode: ");
	scanf("%d", &mode);

	if (mode < 0 || mode > 2) {
		fprintf(stderr, "\nERR: Invalid mode\n");
		return EXIT_FAILURE;
	}

	if (mode == 0) {
		printf("Enter number to test if prime: ");
		scanf("%d", &num);
		mode = is_prime(num);
		if (mode == 1) {
			printf("%d is prime\n", num);
		} else {
			printf("%d is not prime\n", num);
		}
	} else if (mode == 1) {
		printf("Enter starting index: "); 
		scanf("%d", &i);
		printf("Enter ending index: "); 
		scanf("%d", &j);
		if (i == 1) {
			i++;
		}
		show_primes(create_prime_list(j), i, j);
	} else if (mode == 2) {
		printf("Enter number to factor: ");
		scanf("%d", &i);
		prime_factor(i);
	}

	return EXIT_SUCCESS;
}

void prime_factor(int num)
{
	int i = 2, j = 0, k, max = num;
	pair *arr = create_prime_list(num);

	if (!arr[num].is_checked) {
		printf("%d is prime and cannot be factored further\n", num);
		return;
	}

	while (i <= num) {
		if (num % i == 0) {
			j++;
			num /= i;
		} else {
			if (j != 0) {
				printf("%d^%d x ", i, j);
			}
			for (k = i + 1; k < max; k++) {
				if (!arr[k].is_checked) {
					i = k;
					j = 0;
					break;
				}
			}
		}
	}
	if (j != 0) {
		printf("%d^%d\n", i, j);
	}
}

int is_prime(int prime)
{
	pair *arr = create_prime_list(prime);
	if (!arr[prime].is_checked) {
		return 1;
	} else {
		return 0;
	}
}

void show_primes(pair *arr, int start, int end)
{
	int j;
	for (j = start; j <= end; j++) {
		if (!arr[j].is_checked) {
			printf("%d\n", arr[j].number);
		}
	}
}

pair *create_prime_list(int max)
{
	int p, num;
	int index = 2, j;
	pair *arr = malloc(sizeof(pair)*(max+1));

	if (!arr) {
		fprintf(stderr, "malloc returned null\n");
		exit(EXIT_FAILURE);
	}

	for (j = 2; j <= max; j++) {
		arr[j].number = j;
		arr[j].is_checked = 0;
	}

	p = arr[index].number;
	num = 2*p;
	while (index <= max) {
		if (num > max) {
			p = arr[++index].number;
			num = 2*p;		
		} else {
			arr[num].is_checked = 1;
			num += p;
		}
	}
	return arr;
}
