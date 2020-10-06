#include "SceneManager.h"
#include "../Scene/TitleScene.h"

SceneManager::SceneManager()
{
	scenes_.emplace_back(std::make_unique<TitleScene>(*this));
}

void SceneManager::ChangeScene(std::unique_ptr<BaseScene> scene)
{
	auto& playingScene = *scenes_.begin();
	playingScene = std::move(scene);
}

void SceneManager::ProcessInput()
{
	for (const auto& scene : scenes_)
		scene->ProcessInput();
}

void SceneManager::Update(const float& deltaTime)
{
	for (const auto& scene : scenes_)
		scene->Update(deltaTime);
}

void SceneManager::Render(SDL_Renderer* gRenderer)
{
	for (const auto& scene : scenes_)
		scene->Render(gRenderer);
}
