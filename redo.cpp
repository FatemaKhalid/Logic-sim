#include "redo.h"
#include "ApplicationManager.h"


redo::redo(ApplicationManager *pApp) : Action(pApp)
{
}

void redo::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("user want to redo the action");
}

void redo::Execute()
{
	ReadActionParameters();
	if (!pManager->REDO_A.empty())
	{
		pManager->REDO_A.top()->Redo();
		pManager->Actual_A.push(pManager->REDO_A.top());
		pManager->REDO_A.pop();
	}

}

void redo::Undo()
{
}

void redo::Redo()
{
}


redo::~redo()
{
}
