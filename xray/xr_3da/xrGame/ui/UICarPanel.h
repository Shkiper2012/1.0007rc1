#pragma once

#include "uiwindow.h"

class CUICarPanel : public CUIWindow
{
private:
	typedef CUIWindow inherited;

	CUIStatic			UIStaticCarHealth;
	CUIProgressBar		UICarHealthBar;

public: 
	void				SetCarHealth	(float value);
	void				SetSpeed		(float speed);
	void				SetRPM			(float rmp);
	void				Init			(float x, float y, float width, float height);
};