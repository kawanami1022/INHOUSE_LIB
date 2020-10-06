#pragma once
#include <memory>

class SceneManager;

class Application
{
private:
	Application() = default;
	~Application() = default;
	std::unique_ptr<SceneManager> sceneMng_;

	int tickLastFrame = 0;
	bool quit_ = false;
public:
	static Application& Instance();
	bool Initialize();
	void Run();
	void Close();
};

