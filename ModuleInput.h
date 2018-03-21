#ifndef __ModuleInput_H__
#define __ModuleInput_H__

#include "Module.h"
#include "Globals.h"

typedef unsigned char Uint8;

class ModuleInput : public Module
{
public:
	
	ModuleInput();
	~ModuleInput();

	bool Init();
	update_status Update();
	bool CleanUp();

public:
	const Uint8 *keyboard = nullptr;
	bool movement_key[5];
	enum key { UP, LEFT, DOWN, RIGHT, SPACE };
};

#endif // __ModuleInput_H__