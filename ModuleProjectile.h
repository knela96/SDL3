#ifndef __ModuleProjectile_H__
#define __ModuleProjectile_H__

#include "Module.h"

struct SDL_Rect;

typedef unsigned int Uint32;

struct Bullet {
	bool shooting;
	SDL_Rect* bullet;
};

class ModuleProjectile : public Module
{
public:

	ModuleProjectile();
	~ModuleProjectile();

	bool Start();
	update_status Update();
	bool CleanUp();
	bool checkCollision(SDL_Rect* bullet, SDL_Rect* enemy);

public:
	
	SDL_Rect* shoot;
	ModulePlayer* player;
	Bullet bullets[10] = { false, nullptr };
	Uint32* start_time = 0;
	Uint32* shooting_delay;
};

#endif // __ModuleInput_H__
