#ifndef __ModuleRenderer_H__
#define __ModuleRenderer_H__

#include "Module.h"

struct SDL_Renderer;
struct SDL_Texture;
struct SDL_Rect;

class ModuleRender : public Module
{
public:
	ModuleRender();
	~ModuleRender();

	bool Init();
	update_status PostUpdate();
	update_status PreUpdate();
	bool CleanUp();

	void RenderBullets();
	bool Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section = nullptr);

public:
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* tex;
	SDL_Texture* ship;
	SDL_Texture* shoot;
	SDL_Rect* section;
};

#endif //__ModuleRenderer_H__