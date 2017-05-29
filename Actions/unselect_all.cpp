#include "unselect_all.h"






unselect_all::unselect_all(ApplicationManager * pApp) : Action(pApp)

{
}

void unselect_all::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("An empty click on drawing area");
}

void unselect_all::Execute()
{
	ReadActionParameters();
	Input* pIn = pManager->GetInput();
	if (pManager->e7sas(pIn->getsx(), pIn->getsy()) == 0)
		pManager->change_ALL_to_UnHI();

	pManager->Actual_A.push(this);
	while (!pManager->REDO_A.empty())
	{
		pManager->REDO_A.pop();
	}
}

unselect_all::~unselect_all()
{
}
void unselect_all::Undo()
{

}
void unselect_all::Redo()
{

}