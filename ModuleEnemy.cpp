#include "Globals.h"
#include "Application.h"
#include "ModuleEnemy.h"
#include "SDL/include/SDL.h"
#include <time.h>
#include <stdlib.h>

ModuleEnemy::ModuleEnemy() : Module() {}

// Destructor
ModuleEnemy::~ModuleEnemy() {}

// Called before render is available
bool ModuleEnemy::Init()
{
	for (int i = 0; i < 30; ++i) {
		enemies[30].render = false;
		enemies[30].collision = nullptr;
	}
	srand(time(NULL));
	return true;
}

// Called every draw update
update_status ModuleEnemy::Update()
{
	start_time = (Uint32 *)SDL_GetTicks();

	for (int j = 0; j < 30; ++j) {
		if ((start_time - spawn_delay > 1000) && !enemies[j].render) {
			spawn_delay = start_time;
			enemies[j].collision = new SDL_Rect{ SCREEN_WIDTH,(rand() % (SCREEN_HEIGHT - 150)) ,100,100 };
			enemies[j].render = true;
			break;
		}
	}
	

	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleEnemy::CleanUp()
{
	
	return true;
}