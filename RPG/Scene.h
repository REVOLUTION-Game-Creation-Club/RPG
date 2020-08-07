#pragma once
#include "framework.h"

class Scene
{
public:
	enum {
		SCENE_TOWN,
		SCENE_MAX
	};

	Scene() { setSceneType(SCENE_MAX); isCreated = false; }
	virtual ~Scene() {}
	
	virtual void enter(HWND hwnd) { if (!isCreated) { create(hwnd); } }
	virtual void exit() = 0;
	virtual void pause() = 0;
	virtual void resume() = 0;

	virtual void create(HWND hwnd) { isCreated = true; }
	virtual void draw(HDC hdc) = 0;
	virtual void update(const int frame) = 0;

	virtual void getEventMsg(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam) = 0;

protected:
	void setSceneType(const int scene) { sceneType = scene; }

protected:
	int sceneType;
	bool isCreated;
};

