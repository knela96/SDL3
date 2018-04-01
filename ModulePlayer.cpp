#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{
	position.x = 100;
	position.y = 220;


	//({ 4, 4, 36, 10 })

	// idle animation (arcade sprite sheet)
	idle.PushBack({ 100, 0, 36, 16 });

	
	forward.PushBack({ 100, 0, 36, 16 });
	
	backward.PushBack({ 100, 0, 36, 16 });
	
	upward.PushBack({ 48 , 0 , 40 , 16});
	upward.PushBack({ 4, 0, 36, 10 });
	
	

	downward.PushBack({ 150, 0, 40, 16 });
	downward.PushBack({ 195, 0, 40, 16 });


}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("Player.png"); // arcade version
	return ret;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	Animation* current_animation = &idle;

	int speed = 1;

	if (App->input->keyboard[SDL_SCANCODE_D] == 1)
	{
		current_animation = &forward;
		position.x += speed;
	}

	if (App->input->keyboard[SDL_SCANCODE_A] == 1)
	{
		current_animation = &backward;
		position.x -= speed;
	}
	
	if (App->input->keyboard[SDL_SCANCODE_W] == 1)
	{
		current_animation = &upward;
		position.y -= speed;
	}
	
	if (App->input->keyboard[SDL_SCANCODE_S] == 1)
	{
		current_animation = &downward;
		position.y += speed;
	}

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, position.x, position.y - r.h, &r);

	return UPDATE_CONTINUE;
}