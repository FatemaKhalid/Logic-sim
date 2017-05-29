#include "switchtosim.h"


switchtosim::switchtosim(ApplicationManager *pApp) :Action(pApp)
{
}


switchtosim::~switchtosim()
{
}
void switchtosim::ReadActionParameters()
{

}
//Execute action (code depends on action type)
void switchtosim::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->Cleartoolbar();
	pOut->CreateSimulationToolBar();

}

void switchtosim::Undo()
{

}
void switchtosim::Redo()
{

}