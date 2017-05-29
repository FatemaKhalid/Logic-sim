#include "AddLED.h"

#include "..\ApplicationManager.h"
#include "..\Components\LED.h"


AddLED::AddLED(ApplicationManager *pApp) :Action(pApp)
{

}

AddLED::~AddLED(void)
{
}

void AddLED::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("LED : Click to add the led");

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
	 //call fn elahsas
	 //Clear Status Bar
	pOut->ClearStatusBar();

}

void AddLED::Execute()
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
	LED *pA = new LED (GInfo);

	// function 2l27sas 
	pA->updateMatrix(GInfo, pA->getid(), pA->gettype());    //hebaaaaaaaaaa
	pManager->AddComponent(pA);
}



void AddLED::Undo()
{}

void AddLED::Redo()
{}

