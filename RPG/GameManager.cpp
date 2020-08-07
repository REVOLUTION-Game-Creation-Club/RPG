#include "framework.h"
#include "GameManager.h"

GameManager::GameManager()
{

}

GameManager::~GameManager()
{

}

void GameManager::sceneEnter(Scene * newScene)
{
	if (newScene == nullptr) {
		return;
	}
	vScene.push_back(newScene);
	vScene.back()->enter(hWnd_);
}

void GameManager::scenePop()
{
	if (vScene.empty()) {
		return;
	}
	Scene* pScene = vScene.back();
	vScene.pop_back();
	SAFE_DELETE(pScene);
}

void GameManager::sceneChange(Scene * newScene)
{
	scenePop();
	sceneEnter(newScene);
}

void GameManager::getEventMsg(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam)
{
	if (vScene.empty()) {
		exit(0);
		return;
	}
	vScene.back()->getEventMsg(hWnd, nMessageID, wParam, lParam);
}

void GameManager::create(HWND hwnd)
{
	string _str;
	hWnd_ = hwnd;
	//처음 시작할 씬 추가
	sceneEnter(new TownScene());
}

void GameManager::draw(HDC hdc)
{
	if (vScene.empty()) {
		exit(0);
		return;
	}
	vScene.back()->draw(hdc);
}

void GameManager::update(const int frame)
{
	if (vScene.empty()) {
		exit(0);
		return;
	}
	vScene.back()->update(frame);
}
