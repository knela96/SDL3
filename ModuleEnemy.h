#ifndef __ModuleEnemy_H__
#define __ModuleEnemy_H__

#include "Module.h"

struct SDL_Rect;

typedef unsigned int Uint32;

struct Enemy {
	bool render;
	SDL_Rect* collision;
};

class ModuleEnemy : public Module
{
public:

	ModuleEnemy();
	~ModuleEnemy();

	bool Init();
	update_status Update();
	bool CleanUp();

public:
	Enemy enemies[30];
	Uint32* start_time = 0;
	Uint32* spawn_delay;;
};

#endif // __ModuleInput_H__