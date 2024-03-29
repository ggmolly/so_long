/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clocks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 23:44:13 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/31 12:47:18 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_increment_clocks(t_game *game)
{
	register int	i;
	t_animation		*a;

	i = 0;
	while (i < game->animated_objects)
	{
		a = &game->animations[i];
		if (!a->stop)
			++a->clock;
		++i;
	}
	ft_render_animations(game);
}
