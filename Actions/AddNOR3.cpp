#include "AddNOR3.h"
#include "..\ApplicationManager.h"
#include "..\Components\NOR3.h"
AddNOR3::AddNOR3(ApplicationManager *pApp) :Action(pApp)
{

}

AddNOR3::~AddNOR3(void)
{
}

void AddNOR3::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("3-Input NOR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	// calculate the new coordinates "magnet"

	if (Cx % 15 > 7) Cx = Cx / 15 + 1;
	else Cx = Cx / 15;
	//(Cx % 15<= 7)Cx = Cx / 15 - 1;
	if (Cy % 15 > 7) Cy = Cy / 15 + 1;
	else Cy = Cy / 15;
	//if(Cy % 15<= 7)Cy = Cy / 15 - 1;
	Cx *= 15; Cy *= 15;
	while (!pManager->check_matrix(Cx, Cy))
	{
		pOut->PrintMsg("This area is not empty choose another place"); ////hebaaaaa wrbna ystorrrr
		pIn->GetPointClicked(Cx, Cy);
		if (Cx % 15 > 7) Cx = Cx / 15 + 1;
		else Cx = Cx / 15;

		if (Cy % 15 > 7) Cy = Cy / 15 + 1;
		else Cy = Cy / 15;

		Cx *= 15; Cy *= 15;
	}//call fn elahsas
	 
	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddNOR3::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;     //Cx=GInfo.x1+ UI.AND2_Width/2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;     //Cy=GInfo.y1 + UI.AND2_Height/2;
	GInfo.y2 = Cy + Wdth / 2;
	NOR3 *pA = new NOR3(GInfo, AND2_FANOUT);

	// function 2l27sas 
	pA->updateMatrix(GInfo, pA->getid(), pA->gettype());    //hebaaaaaaaaaa
	pManager->AddComponent(pA);
}



void AddNOR3::Undo()
{}

void AddNOR3::Redo()
{}

