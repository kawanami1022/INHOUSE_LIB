#pragma once
#include <memory>
#include <vector>
#include <SDL.h>
#include "../Scene/BaseScene.h"

class SceneManager
{
private:
	friend class Application;
	friend class GameScene;
	friend class TitleScene;

	std::vector<std::unique_ptr<BaseScene>> scenes_;

	void ChangeScene(std::unique_ptr<BaseScene>);

	void ProcessInput();
	void Update(const float& deltaTime);
	void Render(SDL_Renderer*);
public:
	SceneManager();
	~SceneManager() = default;
};

