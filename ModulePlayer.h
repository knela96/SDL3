#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"

struct SDL_Rect;

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
};

#endif // __ModuleInput_H__