#include <stdio.h>
#include <string.h>

extern size_t	ft_strlen(const char *str);
extern char		*ft_strcpy(char *dest, const char *str);
extern int		ft_strcmp(const char *s1, const char *s2);

// TESTS
int main() {

	// ft_strlen
	printf("///// ft_strlen /////\n");

	char l1[] = "I'm a dinosaur !";
	char l2[] = "12345";
	char l3[] = "";
	printf("exp: %zu\t- rec: %zu\t - buf: %s\n", strlen(l1), ft_strlen(l1), l1);
	printf("exp: %zu\t- rec: %zu\t - buf: %s\n", strlen(l2), ft_strlen(l2), l2);
	printf("exp: %zu\t- rec: %zu\t - buf: %s\n", strlen(l3), ft_strlen(l3), l3);
	
	// ft_strcpy
	printf("\n///// ft_strcpy /////\n");

	char dest_test_1[20];
	char dest_original_1[20];
	char src[] = "I'm a dinosaur !";

	char dest_test_2[10];
	char dest_original_2[10];

	printf("exp: %s\t- rec: %s\t - buf: %s\n", strcpy(dest_original_1, src), ft_strcpy(dest_test_1, src), dest_test_1);
	printf("exp: %s\t- rec: %s\t - buf: %s\n", strcpy(dest_original_2, src), ft_strcpy(dest_test_2, src), dest_test_2);

	// ft_strcmp
	printf("\n///// ft_strcmp /////\n");
	
	char cmp1[] = "Hello";
	char cmp2[] = "Hola";

	char cmp3[] = "Hello";
	char cmp4[] = "Hello";

	char cmp5[] = "Hola";
	char cmp6[] = "Hello";


	char cmp7[] = "";
	char cmp8[] = "";

	printf("exp: %d\t- rec: %d\t\n", strcmp(cmp1, cmp2), ft_strcmp(cmp1, cmp2));
	printf("exp: %d\t- rec: %d\t\n", strcmp(cmp3, cmp4), ft_strcmp(cmp3, cmp4));
	printf("exp: %d\t- rec: %d\t\n", strcmp(cmp5, cmp6), ft_strcmp(cmp5, cmp6));
	printf("exp: %d\t- rec: %d\t\n", strcmp(cmp7, cmp8), ft_strcmp(cmp7, cmp8));
}