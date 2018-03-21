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
	//start_time = new Uint32{ SDL_GetTicks() };
	return ret;
}

// Called every draw update
update_status ModulePlayer::Update()
{
	//start_time = SDL_GetTicks();

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
	/*if (App->input->movement_key[App->input->SPACE]) {
		if (start_time - shooting_delay > 250) {
			for (int i = 0; i < 10 && (start_time - shooting_delay > 250); ++i) {
				if (!bullet[i].shooting) {
					shooting_delay = start_time;
					bullet[i].bullet.w = 22;
					bullet[i].bullet.h = 31;
					bullet[i].bullet.x = player->x + player->w;
					bullet[i].bullet.y = player->y + player->h / 2 - bullet[i].bullet.h / 2; ;
					bullet[i].shooting = true;
				}
			}
		}
	}*/

	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModulePlayer::CleanUp()
{
	player = nullptr;
	return true;
}