#include "Multi_select.h"


Multi_select::Multi_select(ApplicationManager * pApp) :Action(pApp)
{
}

void Multi_select::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


	//Print Action Message
	pOut->PrintMsg("Click on gate(s) or connection(s) you want to select. ");
	pIn->getWindowPtr()->FlushMouseQueue();        //HEBA TA3DEEEL WMA3MOL FE SELECT W UN SELECT
												   //Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	if (Cx % 15 != 0)
		Cx = Cx / 15;

	if (Cy % 15 != 0)
		Cy = Cy / 15;


}

void Multi_select::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	char n;
	//n = 0;
	//keytype key = ARROW;
	keytype key = NO_KEYPRESS;
	//	pIn->getWindowPtr()->GetKeyPress(n);
	ReadActionParameters();
	pManager->change_ALL_to_UnHI();
	if (pManager->find_component_with_specific_id(pManager->e7sas(Cx, Cy)) != NULL)
	{
		pManager->find_component_with_specific_id(pManager->e7sas(Cx, Cy))->change_to_HI();
	}
	else
		pManager->change_ALL_to_UnHI();
	pManager->UpdateInterface();      //????hl msmo7ly
	pOut->PrintMsg("Click A to continue or Enter to stop selecting");
	pIn->getWindowPtr()->FlushKeyQueue();     //HEBA TA3DEEEL
	key = pIn->getWindowPtr()->WaitKeyPress(n);
	while (key == ASCII&&n != 13)
	{

		ReadActionParameters();
		if (pManager->find_component_with_specific_id(pManager->e7sas(Cx, Cy)) != NULL)
		{
			pManager->find_component_with_specific_id(pManager->e7sas(Cx, Cy))->change_to_HI();
		}
		else
			pManager->change_ALL_to_UnHI();

		pManager->UpdateInterface();

		pOut->PrintMsg("Click A to continue or Enter to stop selecting");
		pIn->getWindowPtr()->FlushKeyQueue();     // HEBAAAAAAAAAAAAAAA T3DEL
		key = pIn->getWindowPtr()->WaitKeyPress(n);
	}

	pManager->Actual_A.push(this);
	while (!pManager->REDO_A.empty())
	{
		pManager->REDO_A.pop();
	}
}

Multi_select::~Multi_select()
{
}

void Multi_select::Undo()
{

}
void Multi_select::Redo()
{

}