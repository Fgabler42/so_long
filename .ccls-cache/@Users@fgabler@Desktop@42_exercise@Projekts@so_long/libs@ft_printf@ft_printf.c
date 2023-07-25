/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:47:10 by fgabler           #+#    #+#             */
/*   Updated: 2023/07/24 14:17:06 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	scan_restrict_(va_list ap, const char *_restrict_, int *ret_len);
void		put_char_mod(char _restrict_, int *ret_len);
static int	is_it_percent(va_list ap,
				const char *_restrict_, int *ret_len, int *i);

int	ft_printf(const char *_restrict_, ...)
{
	int		ret_len;
	va_list	ap;

	ret_len = 0;
	va_start(ap, _restrict_);
	scan_restrict_(ap, _restrict_, &ret_len);
	return (ret_len);
}

static void	scan_restrict_(va_list ap, const char *_restrict_, int *ret_len)
{
	int	i;

	i = 0;
	while (_restrict_[i])
	{
		if (_restrict_[i] != '%')
			put_char_mod(_restrict_[i++], ret_len);
		else
			is_it_percent(ap, _restrict_, ret_len, &i);
	}
}

static int	is_it_percent(va_list ap,
			const char *_restrict_, int *ret_len, int *i)
{
	*i += 1;
	if (_restrict_[*i] == 'u')
		return (ft_print_uns((va_arg (ap, unsigned int)), ret_len), *i += 1);
	if (_restrict_[*i] == 'i' || _restrict_[*i] == 'd')
		return (ft_print_num((va_arg (ap, int)), ret_len), *i += 1);
	if (_restrict_[*i] == 'c')
		return (put_char_mod((va_arg (ap, int)), ret_len), *i += 1);
	if (_restrict_[*i] == 's')
		return (ft_print_str(va_arg (ap, char *), ret_len), *i += 1);
	if (_restrict_[*i] == 'X')
		return (ft_print_hex((va_arg (ap, int)), 'X', ret_len), *i += 1);
	if (_restrict_[*i] == 'x')
		return (ft_print_hex((va_arg (ap, int)), 'x', ret_len), *i += 1);
	if (_restrict_[*i] == 'p')
		return (ft_print_ptr(va_arg(ap, long unsigned int), ret_len), *i += 1);
	if (_restrict_[*i] == '%')
		return (put_char_mod('%', ret_len), *i += 1);
	return (0);
}
