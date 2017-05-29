#include "Unselect.h"





Unselect::Unselect(ApplicationManager * pApp) : Action(pApp)
{
}

void Unselect::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Click on gate or connection you want to unselect");
	pIn->getWindowPtr()->FlushMouseQueue();
	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	if (Cx % 15 != 0)
		Cx = Cx / 15;

	if (Cy % 15 != 0)
		Cy = Cy / 15;
}

void Unselect::Execute()
{

	ReadActionParameters();
	if (pManager->find_component_with_specific_id(pManager->e7sas(Cx, Cy)) != NULL)
	{
		pManager->find_component_with_specific_id(pManager->e7sas(Cx, Cy))->change_to_UnHI();
	}

	pManager->Actual_A.push(this);
	while (!pManager->REDO_A.empty())
	{
		pManager->REDO_A.pop();
	}
}

Unselect::~Unselect()
{
}
void Unselect::Undo()
{

}
void Unselect::Redo()
{

}