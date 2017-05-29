#include "AddINVERTER.h"
#include "..\ApplicationManager.h"
#include <iostream>
#include <string>
AddINVERTER::AddINVERTER(ApplicationManager *pApp) :Action(pApp)
{
}

AddINVERTER::~AddINVERTER(void)
{
}

void AddINVERTER::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("INVERTER: Click to add the gate");

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

void AddINVERTER::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	Inverter *pA = new Inverter(GInfo, AND2_FANOUT);
	pA->updateMatrix(GInfo, pA->getid(), pA->gettype());






	/*for (int i = 0; i < UI.height / 15 + 1; i++)
	{
	for (int j = 0; j <60; j++)
	{

	cout << ApplicationManager::blablabla[i][j].second;
	//ApplicationManager::blablabla[i][j].second = "empty";
	}
	cout << endl;
	}*/



	pManager->AddComponent(pA);
}

void AddINVERTER::Undo()
{}

void AddINVERTER::Redo()
{}

