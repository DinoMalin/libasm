#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

#define BLUE	"\e[1;34m"
#define RESET	"\033[0m"

extern size_t		ft_strlen(const char *str);
extern char			*ft_strcpy(char *dest, const char *str);
extern int			ft_strcmp(const char *s1, const char *s2);
extern ssize_t		ft_write(int fd, const void *buf, size_t nbytes);
extern ssize_t		ft_read(int fd, const void *buf, size_t nbytes);
extern char			*ft_strdup(const char *s);

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

	// ft_write
	printf("\n///// ft_write /////\n");
	printf("ret: %zd\n", ft_write(1, "dinosaur\n", 9));
	printf("ret: %zd\n", ft_write(1, "", 0));
	printf("ret: %zd - errno: %s\n", ft_write(5, "dino\n", 5), strerror(errno));

	// read
	int fd = open("src/ft_read.s", O_RDONLY);
	char rd_buff1[100] = "";
	int bytes = ft_read(fd, rd_buff1, 99);


	printf("\n///// ft_read /////\n");
	printf("buff: %s[%s]%s...\nret: %d\n", BLUE, rd_buff1, RESET, bytes);

	char rd_buff2[100] = "";
	bytes = ft_read(5, rd_buff2, 99);
	printf("buff: [%s] - ret: %d - errno: %s\n", rd_buff2, bytes, strerror(errno));

	// ft_strdup
	char *dup1 = ft_strdup("I'm a dinosaur !");
	char *dup2 = ft_strdup("");

	printf("\n///// ft_strdup /////\n");
	printf("buff: %s\n", dup1);
	printf("buff: %s\n", dup2);

	free(dup1);
	free(dup2);
}