/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czak </var/mail/czak>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 01:30:29 by czak              #+#    #+#             */
/*   Updated: 2021/12/19 19:54:39 by czak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_data	init(int add)
{
	t_data	img;

	img.zoom = 4;
	img.a = 0;
	img.b = 0;
	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, W_WIDTH, W_HEIGHT, "Fract-ol");
	img.img = mlx_new_image(img.mlx, W_WIDTH, W_HEIGHT);
	img.addr = (int *)mlx_get_data_addr(img.img, &add, &add, &add);
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
			|| argv[2][0] >= '5' || argv[2][0] <= '0')
			return (0);
		img->type = 1;
		img->julia = argv[2][0] - 48;
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
