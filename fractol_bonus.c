/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 21:18:00 by vpogorel          #+#    #+#             */
/*   Updated: 2025/03/06 23:53:49 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_init_style(t_data *data)
{
	data->s = (int **)malloc(sizeof(int *) * 3);
	data->s[0] = (int *)malloc(sizeof(int) * 3);
	data->s[1] = (int *)malloc(sizeof(int) * 3);
	data->s[2] = (int *)malloc(sizeof(int) * 3);
	if (!data->s || !data->s[0] || !data->s[1] || !data->s[2])
	{
		ft_printf("Error: style alloc failed\n");
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		free(data->s[0]);
		free(data->s[1]);
		free(data->s[2]);
		free(data->s);
		exit(1);
	}
}

int	iteration(t_complex z_0, t_complex c, t_data *data)
{
	int	i;

	i = 0;
	if (complex_abs(z_0) >= 4.0)
		return (create_trgb(0, (i * data->t[0]) % 256,
				(i * data->t[1]) % 256, (i * data->t[2]) % 256));
	while (i < 50)
	{
		z_0 = add(multiply(z_0, z_0), c);
		if (complex_abs(z_0) >= 4.0)
			return (create_trgb(0, (i * data->t[0]) % 256,
					(i * data->t[1]) % 256, (i * data->t[2]) % 256));
		i++;
	}
	return (create_trgb (0, 0, 0, 0));
}

static int	render_next_frame(t_data *data)
{
	long double	d[2];
	int			i;
	int			k;
	t_complex	p;

	d[0] = (data->real_max - data->real_min) / data->win_width;
	d[1] = (data->imag_max - data->imag_min) / data->win_height;
	i = 0;
	while (i < data->win_width)
	{
		k = 0;
		while (k < data->win_height)
		{
			p.realpart = data->real_min + d[0] * i;
			p.imagpart = data->imag_max - d[1] * k;
			create_img(data, p, i, k);
			k++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

static void	show_options(t_data *data, int args0, char **args)
{
	if ((args0 == 2) && (ft_strlen(args[1]) == 1)
		&& (args[1][0] == '0' ))
	{
		data->option = 0;
		data->c.realpart = 0.3;
		data->c.imagpart = 0.5;
		return ;
	}
	ft_printf("0: c=(0.3,0.5)\n");
	exit(0);
}

int	main(int args0, char **args)
{
	t_data	data;

	error_init_style(&data);
	show_options(&data, args0, args);
	data.win_height = 750;
	data.win_width = 750;
	data.imag_min = -2;
	data.imag_max = 2;
	data.real_min = -2;
	data.real_max = 2;
	data.zoom = 1;
	data.t = style(&data);
	data.fixated = 0;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, data.win_width, data.win_height,
			"Fractol");
	data.img = mlx_new_image(data.mlx, data.win_width, data.win_height);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			&data.line_length, &data.endian);
	mlx_hook(data.win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.win, 4, 1L << 2, mouse_click, &data);
	mlx_hook(data.win, 17, 1L << 17, close_window, &data);
	mlx_loop_hook(data.mlx, render_next_frame, &data);
	mlx_loop(data.mlx);
	return (0);
}
