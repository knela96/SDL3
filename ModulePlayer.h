#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"

struct SDL_Rect;
//typedef unsigned char Uint32;

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
	//Uint32* start_time;
	//Uint32* shooting_delay;
};

#endif // __ModuleInput_H__