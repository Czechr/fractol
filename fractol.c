
#include "fract_ol.h"

int	mandelbrot_set(float x_axis, float y_axis)
{
	int		iter;
	float	x;
	float	y;
	float	complexe[2];

	iter = 0;
	x = 0;
	y = 0;
	complexe[0] = (x * x) - (y * y) + x_axis;
	complexe[1] = (2 * x * y) + y_axis;
	while (x * x + y * y < 4 && iter < MAX_ITER)
	{
		iter++;
		x = complexe[0];
		y = complexe[1];
		complexe[0] = (x * x) - (y * y) + x_axis;
		complexe[1] = (2 * x * y) + y_axis;
	}
	if (iter == MAX_ITER)
		return (0x000000);
	else
		return (0x53371 + iter);
}

int	julia_set(float x_axis, float y_axis, float *c)
{
	int		iter;
	float	x;
	float	y;
	float	complexe[2];

	iter = 0;
	x = x_axis;
	y = y_axis;
	while (x * x + y * y < 4 && iter < MAX_ITER)
	{
		iter++;
		complexe[0] = (x * x) - (y * y) + c[0];
		complexe[1] = (2 * x * y) + c[1];
		x = complexe[0];
		y = complexe[1];
	}
	if (iter == MAX_ITER)
		return (0x000000 * 10);
	else
		return (0xD4AC0D   + iter * exp(15));
}

void	render(t_data img)
{
	int		i;
	int		j;
	float	x;
	float	y;
	float	*comx;

	i = 0;
	comx = render_julia(img.julia_set);
	while (i++ < W)
	{
		j = 0;
		while (j++ < H)
		{
			x = (((float)i * img.zoom) / W) - (img.zoom / 2);
			y = (((float)j * img.zoom) / H) - (img.zoom / 2);
			if (img.type == 2)
				my_pixelput(img, i, j, mandelbrot_set(x, y));
			else if (img.type == 1)
				my_pixelput(img, i, j, julia_set(x, y, comx));
		}
	}
	free(comx);
}

int	main(int ac, char **av)
{
	int		address;
	t_data	img;

	address = 0;
	img = init(address);
	if (!check(ac, av, &img))
		return (printf(MENU));
	mlx_hook(img.mlx_win,2,0L,close,&img);
	mlx_mouse_hook(img.mlx_win, zoom, &img);
	render(img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop(img.mlx);
	return (1);
}
