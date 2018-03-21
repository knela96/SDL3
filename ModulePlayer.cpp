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

	return ret;
}

// Called every draw update
update_status ModulePlayer::Update()
{
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

	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModulePlayer::CleanUp()
{
	
	return true;
}