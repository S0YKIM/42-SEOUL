#include <mlx.h>
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	printf("Hello from mouse_hook!\n");
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}
