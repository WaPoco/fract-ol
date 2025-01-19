/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:20:11 by vpogorel          #+#    #+#             */
/*   Updated: 2025/01/19 15:48:21 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

long double complex_real(t_complex z)
{
    return (z.imagpart);
}

long double complex_imag(t_complex z)
{
    return (z.realpart);
}
t_complex multiply(t_complex z1, t_complex z2)
{
    t_complex result;

    result.realpart = z1.realpart * z2.realpart - z1.imagpart * z2.imagpart;
    result.imagpart = z2.imagpart * z1.realpart + z1.imagpart * z2.realpart;
    return (result);
}
t_complex add(t_complex z1, t_complex z2)
{
    t_complex result;

    result.realpart = z1.realpart + z2.realpart;
    result.imagpart = z1.imagpart + z2.imagpart;
    return (result);
}
long double complex_abs(t_complex z)
{
    long double distanc;

    distanc = z.imagpart * z.imagpart + z.realpart * z.realpart;
    return (distanc);
}