#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "SDL/include/SDL.h"

ModulePlayer::ModulePlayer() : Module(){}

// Destructor
ModulePlayer::~ModulePlayer(){}

// Called before render is available
bool ModulePlayer::Init()
{
	bool ret = true;
	player = new SDL_Rect{ 0,0,50,50 };
	shoot = new SDL_Rect{ 0,0,50,20 };
	/*for (int i = 0; i < 10; ++i) {
		bullets[i].shooting = false;
	}*/
	return ret;
}

// Called every draw update
update_status ModulePlayer::Update()
{
	
	start_time = (Uint32 *) SDL_GetTicks();

	//Rectangle Movement
	if (App->input->movement_key[App->input->UP] && player->y > 0) {
		player->y--;
	}
	if (App->input->movement_key[App->input->DOWN] && player->y < SCREEN_HEIGHT - player->h) {
		player->y++;
	}
	if (App->input->movement_key[App->input->LEFT] && player->x > 0) {
		player->x--;
	}
	if (App->input->movement_key[App->input->RIGHT] && player->x < SCREEN_WIDTH - player->w) {
		player->x++;
	}
	if (App->input->movement_key[App->input->SPACE]) {
		if (start_time - shooting_delay > 250) {
			for (int i = 0; i < 10 && (start_time - shooting_delay > 250); ++i) {
				if (!bullets[i].shooting) {
					shooting_delay = start_time;
					bullets[i].bullet = new SDL_Rect{ player->x + player->w ,player->y + (player->h / 2) - 15 ,22,31  };
					bullets[i].shooting = true;
					break;
				}
			}
		}
	}

	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModulePlayer::CleanUp()
{
	player = nullptr;
	return true;
}