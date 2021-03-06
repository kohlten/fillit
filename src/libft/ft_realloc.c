/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 22:44:05 by hjo               #+#    #+#             */
/*   Updated: 2018/03/26 22:44:07 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size, size_t prev_size)
{
	void	*newptr;

	if (prev_size <= size)
		return (ptr);
	newptr = malloc(size);
	if (!newptr)
		return (NULL);
	ft_bzero(newptr, size);
	if (!ptr)
		return (newptr);
	ft_memcpy(newptr, ptr, prev_size);
	free(ptr);
	return (newptr);
}
