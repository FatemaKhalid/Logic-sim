#include "undo.h"

#include "ApplicationManager.h"

undo::undo(ApplicationManager *pApp) :Action(pApp)
{
}

void undo::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("user want to undo the action");

}

void undo::Execute()
{
	ReadActionParameters();
if(!pManager->Actual_A.empty())
{
	pManager->Actual_A.top()->Undo();
	pManager->REDO_A.push(pManager->Actual_A.top());
	pManager->Actual_A.pop();
}

}


void undo::Undo()
{
}

void undo::Redo()
{
}

undo::~undo()
{
}
