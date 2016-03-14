#include "will.h"
#include "allegro5\allegro.h"

int main()
{
	al_init();

	ALLEGRO_DISPLAY *display = nullptr;
	al_set_app_name("Hello World from Allegro 5.1!");
	display = al_create_display(640, 480);
	if (display == nullptr)
	{
		std::cerr << "Well, something is not working..." << std::endl;
		al_rest(5.0);
		return EXIT_FAILURE;
	}

	al_clear_to_color(al_map_rgb(255, 255, 255));
	al_flip_display();
	al_rest(5.0);
	return 0;
}