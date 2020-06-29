#include "./includes/libasm.h"
#include <stddef.h>
#include <stdio.h>
# include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
# include <errno.h>

/*typedef struct  s_tests
{
        char    *fct_name;
        int             done;
        int             all;
}                               t_tests;
enum                    e_fct
{
        TOTAL,
        WR, RD, STRCMP, STRLEN, STRCPY, STRDUP,
        e_end
};
extern t_tests test[e_end];

extern int wrfd, rdfd, rdfd_true, g_fail;
extern char err_buff[1024];

int             test_read(const int fd_me, const int fd_true, const int size)
{
        char buf[2][1024];
        int err[2];
        int ret[2];
        int eq[2];
        int all_good;

        errno = 0; 
        bzero(buf[0], sizeof(buf[0]));
        bzero(buf[1], sizeof(buf[1]));
        ret[0] = ft_read(fd_me, buf[0], size);
        err[0] = errno; errno = 0;
        ret[1] = read(fd_true, buf[1], size);
        err[1] = errno;
        eq[0] = (ret[0] == ret[1]); eq[1] = (err[0] == err[1]);
		all_good = (eq[0] && eq[1] && !strcmp(buf[0], buf[1]) ? 1 : 0);
		printf("ft_read:\n    return:%d\nerrno:%d\nread:\n    return:%d\nerrno:%d\n", ret[0],err[0], ret[1],err[1]);
        return (all_good);
}

int main(void)
{
	int fd;
	int fdd;

	fd = open("test.txt", O_RDONLY);
	fdd = open("test.txt", O_RDONLY);
	t_list structure;
  printf("----- FT_STRLEN -----\n");
  printf("REAL || YOURS\n");
	printf("%lu || %zu\n", strlen(""), ft_strlen(""));
   printf("%lu || %zu\n", strlen("lol"), ft_strlen("lol"));

	printf("----- FT_READ -----\n");
	/*if (test_read(fd, 456, 4) == 0)
		printf("OK"); 
	else
		printf("PROBLEM"); 
	int ret;
	ret = (int)ft_read(0, dest, 2);
	printf("ret is %d, read '%.*s'\n", ret, ret, dest);
	ret = (int)ft_read(0, dest, 8);
	printf("ret is %d, read '%.*s'\n", ret, ret, dest);
	printf("----- FT_WRITE -----\n");
	 write(1, "", 0);
	printf("\n");
	ft_write(1, "" ,0);
	printf("\n");
	write(1, "saucisse", 8);
	write(1, "\n", 1);
	ft_write(1, "saucisse", 8);
	char s1[50];
	char s2[50];
	char s3[50];
	char s4[50];
	printf("\n----- FT_STRCPY -----\n");	
	printf("%s\n", strcpy(s1, "lol"));
	printf("%s\n", ft_strcpy(s2, "lol"));
	printf("%s\n", strcpy(s3, ""));
	printf("%s\n", ft_strcpy(s4, ""));
	printf("----- FT_STRDUP -----");
	printf("\n%s\n%s\n%s\n%s\n", strdup("lol"), ft_strdup("lol"), strdup(""), ft_strdup(""));
}*/

int		cmp(void *d1, void *d2)
{
	printf("Compare '%s' - '%s'\n", d1, d2);
	return (((char *)d1)[0] != ((char *)d2)[0]);
}

void	free_fct(void *d1)
{
	printf("Freeing '%s'\n", d1);
}

int		main(void)
{
	printf("-- ft_strlen\n");
	printf("%ld\n", ft_strlen(""));
	printf("%ld\n", ft_strlen("a"));
	printf("%ld\n", ft_strlen("aa"));
	printf("%ld\n", ft_strlen("licorne"));

	char dest[50];
	printf("-- ft_strcpy\n");
	printf("%s\n", ft_strcpy(dest, "licorne"));
	printf("%s\n", ft_strcpy(dest, "aaa"));
	printf("%s\n", ft_strcpy(dest, "aa"));
	printf("%s\n", ft_strcpy(dest, ""));

	printf("-- ft_strcmp\n");
	printf("%d\n", ft_strcmp("a", "b"));
	printf("%d\n", ft_strcmp("", "a"));
	printf("%d\n", ft_strcmp("aaaaa", "a"));
	printf("%d\n", ft_strcmp("a", "aaaaa"));

	printf("-- ft_write\n");
	printf("ret was %ld\n", ft_write(1, "licorne\n", 8));
	printf("ret was %ld\n", ft_write(1, "aaa\n", 4));

	/*
	printf("-- ft_read\n");
	int ret;
	ret = (int)ft_read(0, dest, 2);
	printf("ret is %d, read '%.*s'\n", ret, ret, dest);
	ret = (int)ft_read(0, dest, 8);
	printf("ret is %d, read '%.*s'\n", ret, ret, dest);
	*/

	printf("-- ft_strdup\n");
	printf("'%s'\n", ft_strdup("hello"));
	printf("'%s'\n", ft_strdup("unicorn"));
	printf("'%s'\n", ft_strdup(""));

	t_list *lst = NULL;
	printf("-- ft_list_push_front\n");
	ft_list_push_front(&lst, "licorne");
	ft_list_push_front(&lst, "aya");
	ft_list_push_front(&lst, "ooooo");
	ft_list_push_front(&lst, "popcorn");
	while (lst)
	{
		printf("element: '%s'\n", lst->data);
		t_list *tmp = lst;
		lst = lst->next;
		free(tmp);
	}

	printf("-- ft_list_size\n");
	printf("size = %ld\n", ft_list_size(lst));
	ft_list_push_front(&lst, "aya");
	printf("size = %ld\n", ft_list_size(lst));
	ft_list_push_front(&lst, "ooooo");
	printf("size = %ld\n", ft_list_size(lst));
	ft_list_push_front(&lst, "ddd");
	printf("size = %ld\n", ft_list_size(lst));
	ft_list_push_front(&lst, "ooddd");
	printf("size = %ld\n", ft_list_size(lst));

	printf("-- ft_list_remove_if\n");
	t_list *lst2 = NULL;
	ft_list_push_front(&lst2, "o");
	ft_list_push_front(&lst2, "o");
	ft_list_push_front(&lst2, "o");
	ft_list_push_front(&lst2, "o");
	ft_list_remove_if(&lst2, "o", &cmp, &free_fct);
	printf("res: %p\n", lst2);
	while (lst2)
	{
		printf("element: '%s'\n", lst2->data);
		t_list *tmp = lst2;
		lst2 = lst2->next;
		free(tmp);
	}
}