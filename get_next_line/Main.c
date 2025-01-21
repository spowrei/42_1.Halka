#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() //! iki farklı fonksiyondan read et
{
    int fd = open("test.txt", O_RDONLY);
    char *line;
    
    int i = 0;
    while (i<9)
    {
		line = get_next_line(fd);
		if (!line)
			return (0);
        printf("%s", line);
        free(line);
		i++;
    }
	printf("\n");
	close(fd);
    return (0);
}