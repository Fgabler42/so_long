/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:01:38 by fgabler           #+#    #+#             */
/*   Updated: 2023/07/23 19:54:26 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_hex(unsigned long int num, int *ret_len);

void	ft_print_ptr(unsigned long int num, int *ret_len)
{
	*ret_len += write(1, "0x", 2);
	if (num == 0)
		put_char_mod('0', ret_len);
	else
		put_hex(num, ret_len);
}

static void	put_hex(unsigned long int num, int *ret_len)
{
	if (num >= 16)
	{
		put_hex((num / 16), ret_len);
		put_hex((num % 16), ret_len);
	}
	else
	{
		if (num <= 9)
			put_char_mod((num + 48), ret_len);
		else
			put_char_mod(((num - 10) + 'a'), ret_len);
	}
}
