/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:26:34 by jallerha          #+#    #+#             */
/*   Updated: 2022/04/06 01:51:46 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/mlx.h"
#include "includes/so_long.h"
#include "libft/includes/colors.h"
#include "libft/includes/printf.h"
#include "libft/includes/constants.h"
#include "libft/includes/string.h"
#include <stdlib.h>

// TODO : print warning and show confirmation because map is too big
// (negative size)
void	ft_load_game_sprite(t_game *game)
{
	game->size = ft_table_size(game);
	if (game->size == 64)
		ft_load_sprite_table_file(game, "assets/x64.tbl", 2029441661);
	else if (game->size == 32)
		ft_load_sprite_table_file(game, "assets/x32.tbl", 2764102839);
	else if (game->size == 48)
		ft_load_sprite_table_file(game, "assets/x48.tbl", 1188523485);
	else
	{
		ft_confirm(game);
		game->size = 32;
		ft_load_sprite_table_file(game, "assets/x32.tbl", 2764102839);
	}
}

void	ft_init_game(t_game *game, char *map)
{
	game->moves = 0;
	game->game_clock = 0;
	game->direction = DOWN;
	game->map_data = ft_load_map(map);
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		ft_clean_exit_mlx(1, game);
	ft_load_game_sprite(game);
	ft_create_window(game);
	if (!game->game_window)
		ft_clean_exit_mlx(1, game);
	game->player_image = game->sprites[7].image;
	ft_render_map(game);
	ft_refresh_status(game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2)
	{
		ft_fprintf(STDERR,
			PURPLE1"Usage: %s%s%s <map>\n%sExample :\n\t%s%s%s maps/map_01.ber%s",
			HOTPINK4, argv[0], YELLOW, PURPLE1, HOTPINK4, argv[0], YELLOW, RESET
			);
		ft_clean_exit(1);
	}
	ft_bzero(&game, sizeof(t_game));
	ft_init_game(&game, argv[1]);
	mlx_hook(game.game_window, 17, 0, ft_redcross, &game);
	mlx_hook(game.game_window, 2, 1, ft_key_hook, &game);
	mlx_loop_hook(game.mlx_ptr, ft_loop_hook, &game);
	mlx_loop(game.mlx_ptr);
	ft_clean_exit_mlx(0, &game);
	return (0);
}
