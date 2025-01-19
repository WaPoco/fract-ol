/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 10:30:13 by vpogorel          #+#    #+#             */
/*   Updated: 2025/01/19 17:04:30 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int iteration(t_complex z_0, t_complex c)
{
    int     i;

    i = 0;
    if (complex_abs(z_0)>= 4.0)
        return create_trgb(0, (i * 2) % 256, (i * 2) % 256, (i * 20) % 256);
    while (i < 500)
    {
        z_0 = add(multiply(z_0, z_0), c);
        if (complex_abs(z_0)>= 4.0)
            return create_trgb(0, (i * 2) % 256, (i * 2) % 256, (i * 20) % 256);
        i++;
    }
    return create_trgb(0, 0, 0, 0);
}

int	render_next_frame(t_data *data)
{
	long double	dx;
	long double	dy;
	int			i;
	int			k;
	int			color;
	t_complex		p;
	t_complex		c;

	mlx_clear_window(data->mlx, data->win);
	dx = (data->real_max - data->real_min) / data->win_width;
	dy = (data->imag_max - data->imag_min) / data->win_height;
	i = 0;
	while (i < data->win_width)
	{
		k = 0;
		while (k < data->win_height)
		{
			p.realpart = data->real_min + dx * i;
			p.imagpart = data->imag_max - dy * k;
			c.realpart = 0;
			c.imagpart = 0;
			color = iteration(p, c);
			my_mlx_pixel_put(data, k, i, color);
			k++;
		}
		i++;
	}
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int	main(void)
{
	/*
	if (args0 - 1 != 1)
	*/
	t_data data;

	data.win_height = 500;
	data.win_width  = 500;
	data.imag_min = -2;
	data.imag_max = 2;
	data.real_min = -2;
	data.real_max = 2;
	data.Zoom = 1;
	data.fixated = 0;
	printf("Test1\n");
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.win_width, data.win_height, "Fractol");
	data.img = mlx_new_image(data.mlx, data.win_width, data.win_height);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	printf("Test2\n");
	mlx_loop_hook(data.mlx, render_next_frame, &data);
	printf("Test3\n");
	mlx_loop(data.mlx);
	return (0);
}
