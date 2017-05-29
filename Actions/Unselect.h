#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
#include"..\GUI\Input.h"
#include"..\GUI\Output.h"
class Unselect :
	public Action
{
	int Cx, Cy;
public:
	Unselect(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


	virtual ~Unselect();
};

