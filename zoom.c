
#include "fract_ol.h"
int close(int keys)
{
	if (keys == 53)
		exit(0);
	return(0);
}
int	zoom(int keys, int x, int y, t_data *img)
{	x = x + 1 - 1;
	y = y + 1 - 1;

	if (keys == 5 || keys == 4)
	{
		if (keys== 5)
			img->zoom -= 0.1 * img->zoom;
		else
			img->zoom += 0.1 * img->zoom;
		mlx_clear_window(img->mlx, img->mlx_win);
		render(*img);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	}
	return (0);
}

float	*render_julia(int type)
{
	float	*comx;

	comx = (float *)malloc(sizeof(float) * 2);
	if (!comx)
		return (NULL);
	if (type == 1)
	{
		comx[0] = -0.4;
		comx[1] = 0.6;
	}
	if (type == 2)
	{
		comx[0] = 0.285;
		comx[1] = 0;
	}
	return (comx);
}
