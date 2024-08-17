#include <stdio.h>
#include <string.h>

extern size_t ft_strlen(const char *str);

// TESTS
int main() {

	// ft_strlen
	printf("expected: %zu\t- received: %zu\n", strlen("I'm a dinosaur !"), ft_strlen("I'm a dinosaur !"));
	printf("expected: %zu\t- received: %zu\n", strlen("12345"), ft_strlen("12345"));
	printf("expected: %zu\t- received: %zu\n", strlen(""), ft_strlen(""));
	
}