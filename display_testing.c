#include "inc/so_long.h"

typedef struct pantalla{
	mlx_t *screen;
	mlx_image_t *image;
} pantalla_t;

void	bucle(void *param)
{
	pantalla_t *pantalla = (pantalla_t *)param;
	if (mlx_is_key_down(pantalla->screen, MLX_KEY_D))
		pantalla->image->instances[0].x += 32;

}

int main(void)
{
	pantalla_t pantalla;
	pantalla.screen = mlx_init(100, 100, "manolo", False);
	mlx_texture_t	*player_tx = mlx_load_png("assets/player/FRONT.png");
	pantalla.image = mlx_texture_to_image(pantalla.screen, player_tx);
	mlx_image_to_window(pantalla.screen, pantalla.image, 0, 0);
	mlx_set_setting(MLX_STRETCH_IMAGE, True);
	mlx_loop_hook(pantalla.screen, bucle, &pantalla);
	mlx_loop(pantalla.screen);
}
