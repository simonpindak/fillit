/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zeroing_coordinates.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:44:33 by calpha            #+#    #+#             */
/*   Updated: 2020/01/10 10:52:24 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetramino *zeroing_coordinates(t_tetramino *work_list)
{
	int i;
	int minx;
	int miny;

	i = 0;
	minx = 2147483647;
	miny = 2147483647;
	while (i < 8)
	{
		if (i % 2 == 0)
		{
			if (minx > work_list->blockcoords[i])
				minx = work_list->blockcoords[i];
		}
		else
		{
			if (miny > work_list->blockcoords[i])
				miny = work_list->blockcoords[i];
		}
		i++;
	}
	i = 0;
	while (i < 8)
	{
		if (i % 2 == 0)
			work_list->blockcoords[i] = work_list->blockcoords[i] - minx;
		else
			work_list->blockcoords[i] = work_list->blockcoords[i] - miny;
		i++;
	}
	return (work_list);
}
