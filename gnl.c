#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *get_next_line(int fd)
{
	int rd = 0;
	char c;
	if ((rd = read(fd, &c, 1)) == 0)
		return(NULL);
	char *line = malloc(100000);
	char *word = line;
	*line++ = c;
	while ((rd = read(fd, &c, 1) > 0 && c != '\n'))
		*line++ = c;
	if (c == '\n')
		*line++ = '\n';
	*line = '\0';
	return(word);
}


// int	main(void)
// {
// 	int		r;
// 	char	*line;

// 	line = NULL;
// 	while ((r = get_next_line(&line)) > 0)
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 		line = NULL;
// 	}
// 	printf("%s", line);
// 	free(line);
// 	line = NULL;
// }

#include <fcntl.h>
int	main(void)
{
	int		fd;
	char *line;
	fd = open("hello", O_RDWR);
	if (fd < 0)
	{
		printf("open error\n");
		return (1);
	}
	// while (1)
	// {
		line = get_next_line(fd);
		if (!line)
		{
			printf("end program\n");
			// break ;
		}
		printf("line: -->%s--\n", line);
		free(line);
			line = get_next_line(fd);
		if (!line)
		{
			printf("end program\n");
			// break ;
		}
		printf("line: -->%s--\n", line);
		free(line);
		line = get_next_line(fd);
		if (!line)
		{
			printf("end program\n");
			// break ;
		}
		printf("line: -->%s--\n", line);
		free(line);
		line = get_next_line(fd);
		if (!line)
		{
			printf("end program\n");
			// break ;
		}
		printf("line: -->%s--\n", line);
		free(line);
		line = get_next_line(fd);
		if (!line)
		{
			printf("end program\n");
			// break ;
		}
		printf("line: -->%s--\n", line);
		free(line);
		line = get_next_line(fd);
		if (!line)
		{
			printf("end program\n");
			// break ;
		}
		printf("line: -->%s--\n", line);
		free(line);
		line = get_next_line(fd);
		if (!line)
		{
			printf("end program\n");
			// break ;
		}
		printf("line: -->%s--\n", line);
		free(line);
		// 	line = get_next_line(fd);
		// if (!line)
		// {
		// 	printf("end program\n");
		// 	// break ;
		// }
		// printf("line: -->%s--\n", line);
		// free(line);
	// }
	return(0);
}