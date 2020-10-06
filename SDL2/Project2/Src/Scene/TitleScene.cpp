#include <SDL.h>
#include <SDL_ttf.h>
#include "TitleScene.h"
#include "GameScene.h"
#include "../System/SceneManager.h"
#include "../Constant.h"

TitleScene::TitleScene(SceneManager& sceneMng):BaseScene(sceneMng)
{
}

void TitleScene::ProcessInput()
{
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_SPACE:
			sceneMng_->ChangeScene(std::make_unique<GameScene>(*sceneMng_));
			break;
		default:
			break;
		}
	default:
		break;
	}
}

void TitleScene::Update(const float& deltaTime)
{

}

void TitleScene::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);
}
