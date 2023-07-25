/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 12:22:49 by fgabler           #+#    #+#             */
/*   Updated: 2023/07/24 14:15:09 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_checknum(int ret_from_arg, int *ret_len);

void	ft_print_num(int ret_from_arg, int *ret_len)
{
	if (ret_from_arg == -2147483648)
		*ret_len += write(1, "-2147483648", 11);
	else if (ret_from_arg < 0)
	{
		put_char_mod('-', ret_len);
		ret_from_arg *= -1;
		ft_checknum(ret_from_arg, ret_len);
	}
	else
		ft_checknum(ret_from_arg, ret_len);
}

static void	ft_checknum(int ret_from_arg, int *ret_len)
{
	if (ret_from_arg < 10)
		put_char_mod((ret_from_arg + 48), ret_len);
	if (ret_from_arg > 9)
	{
		ft_checknum((ret_from_arg / 10), ret_len);
		put_char_mod(((ret_from_arg % 10) + '0'), ret_len);
	}
}
