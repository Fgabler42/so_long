/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 19:27:30 by fritzgabler       #+#    #+#             */
/*   Updated: 2023/07/24 14:15:45 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_print_str(const char *ret_from_arg, int *ret_len)
{
	int	i;

	i = 0;
	if (ret_from_arg == NULL)
	{
		*ret_len += write(1, "(null)", 6);
		return ;
	}
	while (ret_from_arg[i])
		put_char_mod(ret_from_arg[i++], ret_len);
}
