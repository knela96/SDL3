#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
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
<<<<<<< HEAD
	/*for (int i = 0; i < 10; ++i) {
	bullets[i].shooting = false;
	}*/
=======
	//start_time = new Uint32{ SDL_GetTicks() };
>>>>>>> parent of 3f80660... Merge branch 'master' of https://github.com/knela96/SDL
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
<<<<<<< HEAD
					bullets[i].bullet = new SDL_Rect{ player->x + player->w ,player->y + (player->h / 2) - 30 ,80,60 };
					bullets[i].shooting = true;
					App->audio->PlayShoot();
					break;
				}
			}
		}
	}


	//Check Collisions
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 30; ++j) {
			if (bullets[i].bullet != nullptr && App->enemy->enemies[j].collision != nullptr) {
				if (checkCollision(bullets[i].bullet, App->enemy->enemies[j].collision)) {
					bullets[i].shooting = false;
					bullets[i].bullet->x = -1000;
					App->enemy->enemies[j].render = false;
					break;
				}
			}
		}
	}

=======
					bullet[i].bullet.w = 22;
					bullet[i].bullet.h = 31;
					bullet[i].bullet.x = player->x + player->w;
					bullet[i].bullet.y = player->y + player->h / 2 - bullet[i].bullet.h / 2; ;
					bullet[i].shooting = true;
				}
			}
		}
	}*/
>>>>>>> parent of 3f80660... Merge branch 'master' of https://github.com/knela96/SDL

	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModulePlayer::CleanUp()
{
	player = nullptr;
	return true;
}