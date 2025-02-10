#include "fdf.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h> //! sil

int main(int argc, char *argv[])
{
	int fd;
	int map_size_x;
	int map_size_y;
	int **map;

	if (argc != 2)
		return (1);
	fd = open(ft_strjoin(ft_strdup("test_maps/"), argv[1]), O_RDONLY);
	if (fd == -1)
	{
		printf("HATA: dosya acilamadi\n");
		return (1);
	}
	map = NULL;
	map_size_x = 0;
	map_size_y = 0;
	if(matris_filler(fd, &map, &map_size_x, &map_size_y) == -1)
		return(1);
	int i;
	int j;
	i = 0;
	while (i < map_size_y-1)
	{
		j  = 0;
		while(j < map_size_x)
		{
			printf("%d ",map[i][j]);
			j++;
		}
		i++;
	}

	return (0);
}