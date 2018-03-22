#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModulePlayer.h"
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#include "ModuleAudio.h"
=======
#include "ModuleEnemy.h"
>>>>>>> 5acbec99611aa121d8e1fadcde172c27e705f0c2
=======
>>>>>>> parent of 3b749a7... Module Audio with assets
=======
>>>>>>> parent of 3b749a7... Module Audio with assets

Application::Application()
{
	modules[0] = window = new ModuleWindow();
	modules[1] = render = new ModuleRender();
	modules[2] = input = new ModuleInput();
	modules[3] = textures = new ModuleTextures();
	modules[4] = player = new ModulePlayer();
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
	modules[5] = audio = new ModuleAudio();
=======
	modules[5] = enemy = new ModuleEnemy();
>>>>>>> 5acbec99611aa121d8e1fadcde172c27e705f0c2
=======
>>>>>>> parent of 3b749a7... Module Audio with assets
=======
>>>>>>> parent of 3b749a7... Module Audio with assets
}	

Application::~Application()
{
	for(int i = NUM_MODULES - 1; i >= 0; --i)
		delete modules[i];
}

bool Application::Init()
{
	bool ret = true;

	for(int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->Init();

	return ret;
}

update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->PreUpdate();

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->Update();

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->PostUpdate();

	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;

	for(int i = NUM_MODULES - 1; i >= 0 && ret == true; --i)
		ret = modules[i]->CleanUp();

	return ret;
}