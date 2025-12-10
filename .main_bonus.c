#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line_bonus.h"

char *get_next_line(int fd);

void    print_line(int fd, char *line)
{
	if (line)
		printf("FD%d: %s", fd, line);
	else
		printf("FD%d: (NULL)\n", fd);
}

int main(void)
{
	int fd1 = open("test.txt", O_RDONLY);
	int fd2 = open("test2.txt", O_RDONLY);
	int fd3 = open("test3.txt", O_RDONLY);

	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
	{
		perror("open");
		return 1;
	}

	char *l1, *l2, *l3;

	while (1)
	{
		// 1st alternating cycle
		l1 = get_next_line(fd1);
		print_line(1, l1);
		free(l1);

		// 2nd FD
		l2 = get_next_line(fd2);
		print_line(2, l2);
		free(l2);

		// 3rd FD
		l3 = get_next_line(fd3);
		print_line(3, l3);
		free(l3);

		printf("-------------------------------\n");

		if (!l1 && !l2 && !l3)
			break;
	}

	close(fd1);
	close(fd2);
	close(fd3);
	return 0;
}
