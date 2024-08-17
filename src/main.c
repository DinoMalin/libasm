#include <stdio.h>
#include <string.h>

extern size_t	ft_strlen(const char *str);
extern char		*ft_strcpy(char *dest, const char *str);

// TESTS
int main() {

	// ft_strlen
	printf("///// ft_strlen /////\n");

	char t1[] = "I'm a dinosaur !";
	char t2[] = "12345";
	char t3[] = "";
	printf("exp: %zu\t- rec: %zu\t - buf: %s\n", strlen(t1), ft_strlen(t1), t1);
	printf("exp: %zu\t- rec: %zu\t - buf: %s\n", strlen(t2), ft_strlen(t2), t2);
	printf("exp: %zu\t- rec: %zu\t - buf: %s\n", strlen(t3), ft_strlen(t3), t3);
	
	// ft_strcpy
	printf("\n///// ft_strcpy /////\n");

	char dest_test_1[20];
	char dest_original_1[20];
	char src[] = "I'm a dinosaur !";

	char dest_test_2[10];
	char dest_original_2[10];

	printf("exp: %s\t- rec: %s\t - buf: %s\n", strcpy(dest_original_1, src), ft_strcpy(dest_test_1, src), dest_test_1);
	printf("exp: %s\t- rec: %s\t - buf: %s\n", strcpy(dest_original_2, src), ft_strcpy(dest_test_2, src), dest_test_2);
}