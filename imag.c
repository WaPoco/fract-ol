/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:09:16 by vpogorel          #+#    #+#             */
/*   Updated: 2025/02/21 22:25:32 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	*style(void)
{
	int			**t;
	static int	i;

	t = (int **)malloc(sizeof(int *) * 3);
	t[0] = (int *)malloc(sizeof(int) * 3);
	t[1] = (int *)malloc(sizeof(int) * 3);
	t[2] = (int *)malloc(sizeof(int) * 3);
	t[0][0] = 2;
	t[0][1] = 5;
	t[0][2] = 7;
	t[1][0] = 3;
	t[1][1] = 2;
	t[1][1] = 5;
	t[2][0] = 7;
	t[2][1] = 14;
	t[2][2] = 80;
	i += 1;
	i = i % 3; 
	return (t[i]);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	create_img(t_data *data, t_complex p, int x, int y)
{
	int		color;

	if (data->option == '1')
	{
		data->c.realpart = 0;
		data->c.imagpart = 0;
		color = iteration(data->c, p, data);
		my_mlx_pixel_put(data, x, y, color);
		return ;
	}
	color = iteration(p, data->c, data);
	my_mlx_pixel_put(data, x, y, color);
}
