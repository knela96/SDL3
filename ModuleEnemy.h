#ifndef __ModuleEnemy_H__
#define __ModuleEnemy_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

struct SDL_Rect;
struct SDL_Texture;

typedef unsigned int Uint32;

struct Enemy {
	SDL_Rect* collision;
	SDL_Texture* graphics = nullptr;
	Animation forward;
	iPoint position;
};

class ModuleEnemy : public Module
{
public:

	ModuleEnemy();
	~ModuleEnemy();

	bool Start();
	update_status Update();

public:
	Enemy enemies[30];
	Uint32* start_time = 0;
	Uint32* spawn_delay;

<<<<<<< HEAD
=======
	Animation anim;
>>>>>>> 6a308cc207e3909ba513ae72a8bad9604fef8387
};

#endif // __ModuleInput_H__