/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkollar <mkollar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 15:54:26 by mkollar           #+#    #+#             */
/*   Updated: 2025/02/05 11:35:10 by mkollar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#define WIDTH 1236
#define HEIGHT 1280

bool file_exists(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file)
    {
        fclose(file);
        return true;
    }
    return false;
}

void	load_image_on_screen(mlx_t **main_mlx, const char *image_path)
{
		mlx_t *mlx = *main_mlx;
    // Load an image from a PNG file
    mlx_texture_t* tex = mlx_load_png(image_path);
    if (!tex)
    {
        fprintf(stderr, "Failed to load image\n");
        mlx_terminate(mlx);
        return ;
    }

    // Convert the texture to an image
    mlx_image_t* img = mlx_texture_to_image(mlx, tex);
    if (!img)
    {
        fprintf(stderr, "Failed to convert texture to image\n");
        mlx_delete_texture(tex);
        mlx_terminate(mlx);
        return ;
    }

    // Draw the image at coordinate (0, 0)
    mlx_image_to_window(mlx, img, 0, 0);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	mlx_t **main_mlx = (mlx_t **)param;

	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		load_image_on_screen(main_mlx, "character.png");
	}
}

int32_t main(void)
{
	  const char *image_path = "map.png";

    // Check if the image file exists
    if (!file_exists(image_path))
    {
        fprintf(stderr, "Image file does not exist: %s\n", image_path);
        return EXIT_FAILURE;
    }

    // Initialize MLX42 with a window size of 1920x1080
    mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Display Image", true);
    if (!mlx)
    {
        fprintf(stderr, "MLX42 initialization failed\n");
        return EXIT_FAILURE;
    }
		load_image_on_screen(&mlx, image_path);
		mlx_key_hook(mlx, &key_hook, &mlx);
    // Run the main loop and terminate on quit
    mlx_loop(mlx);
    mlx_terminate(mlx);

    return EXIT_SUCCESS;
}
