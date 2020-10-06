#pragma once
#include <SDL.h>
#include "BaseScene.h"
class TitleScene :
    public BaseScene
{
public:
    TitleScene(SceneManager&);
    ~TitleScene() = default;
    void ProcessInput() override;
    void Update(const float& deltaTime) override;
    void Render(SDL_Renderer* renderer) override;
};

