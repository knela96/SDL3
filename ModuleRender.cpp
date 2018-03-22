#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleWindow.h"
#include "ModulePlayer.h"
#include "ModuleTextures.h"
#include "SDL/include/SDL.h"

ModuleRender::ModuleRender() : Module()
{}

// Destructor
ModuleRender::~ModuleRender()
{}

// Called before render is available
bool ModuleRender::Init()
{
	LOG("Creating Renderer context");
	bool ret = true;
	Uint32 flags = 0;

	if (REN_VSYNC == true)
	{
		flags |= SDL_RENDERER_PRESENTVSYNC;
	}

	renderer = SDL_CreateRenderer(App->window->window, -1, flags);

	if (renderer == NULL)
	{
		LOG("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	// TODO 9: load a texture "test.png" to test is everything works well
	tex = App->textures->Load("Assets/Tilemaplvl1.png");
	ship = App->textures->Load("Assets/ship.png");
	shoot = App->textures->Load("Assets/shoot.png");
	return ret;
}

// Called every draw update
update_status ModuleRender::PreUpdate()
{
	//makes the scrollig offet move and if its lesser than the texture size, it 
	//reinizializes to 0
	--ScrollingOffset;
	if (ScrollingOffset < -1536)
	{
		ScrollingOffset = 0;
	}
	// TODO 7: Clear the screen to black before starting every frame
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_RenderClear(renderer);
	// TODO 10: Blit our test texture to check functionality


	section = new SDL_Rect{ 0,0, 1536, 1536 };//x-position,y-position,width-img,height-img


	Blit(tex, ScrollingOffset, 0, section);
	Blit(tex, ScrollingOffset + 1536, 0, section);

	SDL_RenderCopyEx(renderer, ship, NULL, App->player->player, 0, NULL, SDL_FLIP_NONE);
	//SDL_RenderCopyEx(renderer, shoot, NULL, App->player->shoot, 0, NULL, SDL_FLIP_NONE);

	//Bullets();


	return update_status::UPDATE_CONTINUE;
}

update_status ModuleRender::PostUpdate()
{
	// TODO 8: Switch buffers so we actually render
	SDL_RenderPresent(renderer);

	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleRender::CleanUp()
{
	LOG("Destroying renderer");

	//Destroy window
	if (renderer != nullptr)
		SDL_DestroyRenderer(renderer);

	return true;
}

// Blit to screen
bool ModuleRender::Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section)
{
	bool ret = true;
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;

	if (section != nullptr)
	{
		rect.w = section->w;
		rect.h = section->h;
	}
	else
	{
		SDL_QueryTexture(texture, nullptr, nullptr, &rect.w, &rect.h);
	}

	if (SDL_RenderCopy(renderer, texture, section, &rect) != 0)
	{
		LOG("Cannot blit to screen. SDL_RenderCopy error: %s", SDL_GetError());
		ret = false;
	}

	return ret;
}

void ModuleRender::Bullets() {
	//Move Bullets
	/*
	for (int i = 0; i < 10; ++i) {
		if (bullet[i].shooting && bullet[i].bullet.x < SCREEN_WIDTH) {
			bullet[i].bullet.x += 2;
			SDL_RenderCopyEx(renderer, shoot, NULL, &bullet[i].bullet, 0, NULL, SDL_FLIP_NONE);
		}
		else {
<<<<<<< HEAD
			App->player->bullets[i].shooting = false;
		}
	}
}

void ModuleRender::RenderEnemies() {
	for (int j = 0; j < 30; ++j) {
		if (App->enemy->enemies[j].collision != nullptr) {
			if (App->enemy->enemies[j].render && App->enemy->enemies[j].collision->x > 0) {
				--App->enemy->enemies[j].collision->x;
				SDL_RenderCopyEx(renderer, enemy, NULL, App->enemy->enemies[j].collision, 0, NULL, SDL_FLIP_NONE);
			}
			else {
				App->enemy->enemies[j].collision->x = -500;
			}
			break;
=======
			bullet[i].shooting = false;
>>>>>>> parent of 3f80660... Merge branch 'master' of https://github.com/knela96/SDL
		}
	}*/
}
