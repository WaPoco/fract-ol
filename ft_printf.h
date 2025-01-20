/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpogorel <vpogorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 13:36:47 by vpogorel          #+#    #+#             */
/*   Updated: 2024/12/06 11:25:15 by vpogorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_check_flag(va_list args, char flag, int *count);
void	ft_print_char(va_list args, int *count);
void	ft_print_decimal(va_list args, int *count);
void	ft_print_number_hex(va_list args, char c, int *count);
void	ft_print_percent(int *count);
void	ft_print_pointer(va_list args, int *count);
void	ft_print_string(va_list args, int *count);
void	ft_print_udecimal(va_list args, int *count);

#endif
