#include "minilibx-linux/mlx.h"
#include <stdio.h>

int	close_window(int keycode, void *param)
{
    if (keycode == 65307)  // ESC tuşunun keycode'u 65307
    {
        mlx_loop_end(param);
    }
    return (0);
}

int main()
{
	void *mlx;
	void *window;
	void *image;

	mlx = mlx_init();
	if (!mlx)
	{
		printf("init fail\n");
		return (1);
	}
	window = mlx_new_window(mlx, 400, 400, "test");
	if(!window)
	{
		printf("window fail\n");
		return (1);
	}
	
	image = mlx_new_image(mlx, 400, 400);
	mlx_key_hook(window, close_window, mlx);
	mlx_put_image_to_window(mlx, window, img.img, 0, 0);
	mlx_loop(mlx);
	printf("finito\n");
	return (0);
}