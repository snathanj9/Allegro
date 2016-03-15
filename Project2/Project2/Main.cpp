#include "will.h"
#include "allegro5\allegro.h"
#include "allegro5\allegro_acodec.h"
#include "allegro5\allegro_audio.h"

enum MYKEYS
{
	KEY_UP,
	KEY_DOWN,
	KEY_LEFT,
	KEY_RIGHT

};

const int FPS = 60;

bool key[5]{ false, false, false, false, false };

int main()
{
	bool doExit = false;
	bool played = false;
	

	ALLEGRO_DISPLAY *display = nullptr;
	al_set_app_name("Hello World from Allegro 5.1!");
	ALLEGRO_EVENT_QUEUE *queue = NULL;
	ALLEGRO_SAMPLE *sample = NULL;
	ALLEGRO_TIMER *timer = NULL;

	//allegro init
	al_init();
	al_init_acodec_addon();

	// allegro installs
	al_install_keyboard();
	al_install_audio();
	al_reserve_samples(1);

	display = al_create_display(640, 480);
	timer = al_create_timer(1.0 / FPS);
	queue = al_create_event_queue();

	sample = al_load_sample("../Dependencies/Audio/Ages3.ogg");

	if (!sample)
	{
		std::cerr << "sample is a bitch" << std::endl;
	}

	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_register_event_source(queue, al_get_keyboard_event_source());
	
	al_start_timer(timer);

	while (!doExit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER)
		{
		}

		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = true;
				break;

			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = false;
				break;
			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = false;
				break;
			case ALLEGRO_KEY_ESCAPE:
				doExit = true;
				break;

			}
		}
			
			if (al_is_event_queue_empty(queue))
			{
				if (!played)
				{
					al_play_sample(sample, 0.5, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
					played = true;
				}

				al_clear_to_color(al_map_rgb(255, 255, 255));
				al_flip_display();
			}
		


	}
	
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(queue);

	return 0;
}