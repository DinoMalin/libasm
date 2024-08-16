#include <stdio.h>

extern size_t ft_strlen(const char *str);

// TESTS
int main() {

	// ft_strlen
	printf("len: %zu\n", ft_strlen("I'm a dinosaur !"));
	printf("len: %zu\n", ft_strlen("12345"));
	printf("len: %zu\n", ft_strlen(""));
}