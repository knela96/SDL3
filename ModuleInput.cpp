#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "SDL/include/SDL.h"

ModuleInput::ModuleInput() : Module()
{}

// Destructor
ModuleInput::~ModuleInput()
{}

// Called before render is available
bool ModuleInput::Init()
{
	LOG("Init SDL input event system");
	bool ret = true;
	SDL_Init(0);

	if(SDL_InitSubSystem(SDL_INIT_EVENTS) < 0)
	{
		LOG("SDL_EVENTS could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}
	for (int i = 0; i < 5; ++i) {
		movement_key[i] = false;
	}

	LOG("%i",movement_key[LEFT]);
	return ret;
}

// Called every draw update
update_status ModuleInput::Update()
{
	SDL_PumpEvents();

	keyboard = SDL_GetKeyboardState(NULL);

	// TODO 1: find out how to detect if the ESC key was pressed
	// and quit the game
	if (keyboard[SDL_SCANCODE_ESCAPE]) {
		return  update_status::UPDATE_STOP;
	}
	movement_key[UP] = (keyboard[SDL_SCANCODE_W]) ? true : false;
	movement_key[LEFT] = (keyboard[SDL_SCANCODE_A]) ? true : false;
	movement_key[DOWN] = (keyboard[SDL_SCANCODE_S]) ? true : false;
	movement_key[RIGHT] = (keyboard[SDL_SCANCODE_D]) ? true : false;
	movement_key[SPACE] = (keyboard[SDL_SCANCODE_SPACE]) ? true : false;

	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleInput::CleanUp()
{
	LOG("Quitting SDL input event subsystem");
	SDL_QuitSubSystem(SDL_INIT_EVENTS);
	return true;
}