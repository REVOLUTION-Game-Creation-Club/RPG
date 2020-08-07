#include "framework.h"
#include "TownScene.h"

TownScene::TownScene()
{
	setSceneType(SCENE_TOWN);
}

void TownScene::enter(HWND hwnd)
{
}

void TownScene::exit()
{
}

void TownScene::pause()
{
}

void TownScene::resume()
{
}

void TownScene::create(HWND hwnd)
{
	Scene::create(hwnd);
}

void TownScene::draw(HDC hdc)
{
}

void TownScene::update(const int frame)
{
}

void TownScene::getEventMsg(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
}
