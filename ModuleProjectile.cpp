#include "Globals.h"
#include "Application.h"
#include "ModuleProjectile.h"
#include "ModuleEnemy.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "SDL/include/SDL.h"

ModuleProjectile::ModuleProjectile() : Module() {}

// Destructor
ModuleProjectile::~ModuleProjectile() {}

// Called before render is available
bool ModuleProjectile::Init()
{
	bool ret = true;
	
	shoot = new SDL_Rect{ 0,0,80,50 };
	/*for (int i = 0; i < 10; ++i) {
	bullets[i].shooting = false;
	}*/
	return ret;
}

// Called every draw update
update_status ModuleProjectile::Update()
{
	player = new ModulePlayer;

	start_time = (Uint32 *)SDL_GetTicks();

	//Rectangle Movement
	
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {
		if (start_time - shooting_delay > 250) {
			for (int i = 0; i < 10 && (start_time - shooting_delay > 250); ++i) {
				if (!bullets[i].shooting) {
					shooting_delay = start_time;
					bullets[i].bullet = new SDL_Rect{ player->position.x + /*player->w*/ 15 , player->position.y  /* + (player->h / 2) - 30 ,80,60 */};
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
					App->enemy->enemies[j].position.x = -100;
					break;
				}
			}
		}
	}


	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleProjectile::CleanUp()
{
	for (int i = 0; i < 10; ++i) {
		bullets[i].bullet = nullptr;
	}
	player = nullptr;
	return true;
}

bool ModuleProjectile::checkCollision(SDL_Rect* bullet, SDL_Rect* enemy) {
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = bullet->x;
	rightA = bullet->x + bullet->w;
	topA = bullet->y;
	bottomA = bullet->y + bullet->h;

	//Calculate the sides of rect B
	leftB = enemy->x;
	rightB = enemy->x + enemy->w;
	topB = enemy->y;
	bottomB = enemy->y + enemy->h;

	//If any of the sides from A are outside of B
	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}