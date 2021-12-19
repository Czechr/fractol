
#include "fract_ol.h"

t_data	init(int address)
{
	t_data	img;

	img.zoom = 4;
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, W, H, "Fract-ol");
	img.img = mlx_new_image(img.mlx, W, H);
	img.addr = (int *)mlx_get_data_addr(img.img, &address, &address, &address);
	return (img);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	check(int argc, char **argv, t_data *img)
{
	if (argc != 2 && argc != 3)
		return (0);
	if (ft_strcmp(argv[1], "Julia"))
	{
		if (argc != 3 || ft_strlen(argv[2]) != 1
			|| argv[2][0] >= '3' || argv[2][0] <= '0')
			return (0);
		img->type = 1;
		img->julia_set = argv[2][0] - 48;
	}
	else if (ft_strcmp(argv[1], "Mandelbrot"))
	{
		if (argc != 2)
			return (0);
		img->type = 2;
	}
	else
		return (0);
	return (1);
}
