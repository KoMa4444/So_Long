/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koma <koma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:54:26 by mkollar           #+#    #+#             */
/*   Updated: 2025/01/29 14:05:04 by koma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#define WIDTH 1920
#define HEIGHT 1080
#define BPP sizeof(int32_t)

int32_t	main(void)
{
		// Init mlx with a canvas size of 256x256 and the ability to resize the window.
		mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "josetonto", true);

		if (!mlx) exit(EXIT_FAILURE);

		// Create a fullscrean image.
		mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);

		// Set the channels of each pixel in our image to the maximum byte value of 255. 
		memset(img->pixels, 255, img->width * img->height * BPP);

		// Draw the image at coordinate (0, 0).
		mlx_image_to_window(mlx, img, 0, 0);

		// Run the main loop and terminate on quit.  
		mlx_loop(mlx);
		mlx_terminate(mlx);

		return (EXIT_SUCCESS);
}
