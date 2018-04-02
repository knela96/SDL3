#include "Globals.h"
#include "Application.h"
#include "ModuleProjectile.h"
#include "ModuleEnemy.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleAudio.h"
#include "SDL/include/SDL.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"

ModuleProjectile::ModuleProjectile() : Module() {


	singleshot.PushBack({ 64, 30, 17, 18});
	singleshot.speed = 0.1f;


}

// Destructor
ModuleProjectile::~ModuleProjectile() {}

// Called before render is available
bool ModuleProjectile::Start()
{
	bool ret = true;
	
	
	LOG("Loading player textures");
	
	graphics = App->textures->Load("Player.png"); // arcade version
	
	return ret;
}

// Called every draw update
update_status ModuleProjectile::Update()
{
	player = App->player;
	Animation* current_animation = &singleshot;
	SDL_Rect r = current_animation->GetCurrentFrame();
	int speed = 1;


	start_time = (Uint32 *)SDL_GetTicks();

	//Rectangle Movement
	
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {
		if (start_time - shooting_delay > 250) {
			for (int i = 0; i < 10 && (start_time - shooting_delay > 250); ++i) {
				if (bullets[i].bullet == nullptr) {
					shooting_delay = start_time;
					bullets[i].bullet = new SDL_Rect{ player->position.x + /* player->w */ 15 , player->position.y  /* + (player->h / 2) - 30 ,80,60 */ };
					App->audio->PlayShoot();
					bullets[i].position.x = App->player->position.x;
					bullets[i].position.y = App->player->position.y;
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
					bullets[i].bullet = nullptr;
					App->enemy->enemies[j].collision = nullptr;
					break;
				}
			}
		}
	}

	for (int i = 0; i < 10; ++i) {
		if (bullets[i].bullet != nullptr) {
			if (bullets[i].position.x > SCREEN_WIDTH) {
				bullets[i].bullet = nullptr;
			}
			else {
				bullets[i].position.x += 2;
				App->render->Blit(graphics, bullets[i].position.x, bullets[i].position.y - r.h, &r);
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