/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahel-mou <ahel-mou@student-1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:58:10 by ahel-mou          #+#    #+#             */
/*   Updated: 2021/12/07 08:18:41 by ahel-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGRAM_H
# define PROGRAM_H

# include <unistd.h>
# include <stdarg.h>
# include <signal.h>
//# include <stdio.h>
//# include <string.h>

//-------------------- printf

int			var_type(char cara, va_list l_o_arg);
int			base_num_len(size_t num, size_t base);
int			ft_putnbr_base(int num, char *cara);
int			ft_putnbr_base_unsigned(unsigned int num, char *base);
int			ft_putchar(char cara);
int			ft_putstr(char *cara);
int			ft_pt_address(void *add);
size_t		ft_strlen(char *cara);
int			ft_printf(const char *cara, ...);

//-------------------- minitalk



#endif