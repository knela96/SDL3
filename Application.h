#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 5

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModulePlayer;
class ModuleEnemy;
class Module;

class Application
{
public:

	Module* modules[NUM_MODULES] = { nullptr };
	ModuleWindow* window = nullptr;
	ModuleRender* render = nullptr;
	ModuleInput* input = nullptr;
	ModuleTextures* textures = nullptr;
	ModulePlayer* player = nullptr;
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
	ModuleAudio* audio = nullptr;
=======
	ModuleEnemy* enemy = nullptr;
>>>>>>> 5acbec99611aa121d8e1fadcde172c27e705f0c2
=======
>>>>>>> parent of 3b749a7... Module Audio with assets
=======
>>>>>>> parent of 3b749a7... Module Audio with assets

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__