#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"

struct SDL_Rect;

typedef unsigned int Uint32;

struct Bullet {
	bool shooting;
	SDL_Rect* bullet;
};

class ModulePlayer : public Module
{
public:

	ModulePlayer();
	~ModulePlayer();

	bool Init();
	update_status Update();
	bool CleanUp();

public:
	SDL_Rect* player;
	SDL_Rect* shoot;
	Bullet bullets[10] = { false };
	Uint32* start_time = 0;
	Uint32* shooting_delay;
};

#endif // __ModuleInput_H__