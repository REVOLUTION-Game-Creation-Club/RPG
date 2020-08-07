#pragma once
#include "framework.h"

class Scene;
class GameManager
{
public:
	static GameManager* getInstance() {
		static GameManager instance;
		return &instance;
	}

	void sceneEnter(Scene* newScene);
	void scenePop();
	void sceneChange(Scene* newScene);

	void getEventMsg(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);

	void create(HWND hwnd);
	void draw(HDC hdc);
	void update(const int frame);

	HWND hWnd_;
	vector<Scene*> vScene;

protected:
	GameManager();
	~GameManager();
};

