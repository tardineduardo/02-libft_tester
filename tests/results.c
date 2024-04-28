/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:14:07 by eduribei          #+#    #+#             */
/*   Updated: 2024/04/23 15:10:45 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str++)
	{
		count++;
	}
	return (count);
}

void	ft_save_results(char *str)
{
	int	file;
		
	file = open("results.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);	
	if (file != -1)
	{
		write(file, "[", 1);
		write(file, str, ft_strlen(str));
		write(file, "]", 1);		
		write(file, ",", 2);
	}
	else
	{
		write(1, "Cannot open file.\n", 18);
	}
	close(file);
}
