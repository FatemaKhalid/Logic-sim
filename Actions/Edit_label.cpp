
#include "..\ApplicationManager.h"
#include<string>
#include<iostream>
using namespace std;
#include "Edit_label.h"

Edit_label::Edit_label(ApplicationManager *pApp) :Action(pApp)
{
}
void Edit_label::ReadActionParameters() {
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Click on gate or connection you want to edit its label ");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	//component_id=pManager->e7sas(Cx, Cy);
	if (Cx % 15 != 0)
		Cx = Cx / 15;

	if (Cy % 15 != 0)
		Cy = Cy / 15;

	pOut->PrintMsg("Write the label");
	label = pIn->GetSrting(pOut);
	if (label.length() > 5)
		label = label.substr(0, 5);

	pManager->Actual_A.push(this);
	while (!pManager->REDO_A.empty())
	{
		pManager->REDO_A.pop();
	}
	//Clear Status Bar
	pOut->ClearStatusBar();

}
//Execute action (code depends on action type)
void Edit_label::Execute() {
	ReadActionParameters();
	Component* pp = pManager->find_component_with_specific_id(pManager->e7sas(Cx, Cy));
	if (pp != NULL)
	{
		id_done = pManager->e7sas(Cx, Cy);
		last_label = pp->getlabel();
		pp->edit_label(label);
	}
}


void Edit_label::Undo() {
	Component* p = pManager->find_component_with_specific_id(id_done);
	if (p != NULL)
	{
		p->edit_label(last_label);
	}

}
void Edit_label::Redo() {

	Component* p = pManager->find_component_with_specific_id(id_done);
	if (p != NULL)
	{
		p->edit_label(label);
	}
}


Edit_label::~Edit_label(void)
{
}
