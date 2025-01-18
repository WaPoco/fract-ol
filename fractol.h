/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 10:30:17 by vpogorel          #+#    #+#             */
/*   Updated: 2025/01/18 12:18:57 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include </home/vasili/Documents/minilibx-linux/mlx.h>

typedef struct s_data {
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			win_width;
	int			win_height;
	long double	Zoom;
	long double	real_min;
	long double	real_max;
	long double	imag_max;
	long double	imag_min;
	long double	fixed_x;
	long double	fixed_y;
	int			fixated;
}              t_data;

typedef struct complex_number
{
	long double	realpart;
	long double	imagpart;	
}				complex;

long double	creal(complex z);
long double	cimag(complex z);
complex		multiply(complex z1, complex z2);
complex		add(complex z1, complex z2);
long double abs(complex z);
int	create_trgb(int t, int r, int g, int b);

#endif