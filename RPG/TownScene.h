#pragma once
class TownScene: public Scene
{
public:
	TownScene();
	virtual ~TownScene() {}

	virtual void enter(HWND hwnd);
	virtual void exit();
	virtual void pause();
	virtual void resume();

	virtual void create(HWND hwnd);
	virtual void draw(HDC hdc);
	virtual void update(const int frame);

	void getEventMsg(HWND hWnd, UINT nMessageID, WPARAM wParam, LPARAM lParam);
protected:

};

