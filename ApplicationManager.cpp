#include "ApplicationManager.h"
#include"Actions/AddGate.h"
#include"Actions/Edit_label.h"
#include"Actions/Multi_select.h"
#include"Actions/Select.h"
#include"Actions/SwitchBack.h"
#include"Actions/unselect_all.h"
#include"Actions/Unselect.h"
#include"Actions/switchtosim.h"
#include"Actions/switchtodesign.h"
#include"Actions/AddAND2.h"
#include "Actions/AddBuffer.h"
#include "Actions/AddINVERTER.h"
#include "Actions/AddOR2.h"
#include "Actions/AddNOR2.h"
#include"Actions/AddXNOR2.h" 
#include "Actions/AddXOR2.h"
#include "Actions/AddAND3.h"
#include "Actions/AddNOR3.h"
#include "Actions/AddXOR3.h"
#include "Actions/AddSWITCH.h"
#include "Actions/AddLED.h"
#include "Actions/AddNAND2.h"
#include"redo.h"
#include"undo.h"
#include"select_area.h"
#include"Actions/AddNOT.h"

std::pair<int, std::string> ApplicationManager::blablabla[UI.height/15+1][UI.width/15+1];

ApplicationManager::ApplicationManager()
{
	CompCount = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
	fillmatrix();
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	
	switch (ActType)
	{
	case ADD_AND_GATE_2:
		pAct = new AddAND2(this);
		break;

	case ADD_AND_GATE_3:
		pAct = new AddAND3(this);
		break;

	case ADD_Buff:
		pAct = new AddBuffer(this);
		break;

	case ADD_NOR_GATE_2:
		pAct = new AddNOR2(this);
		break;

	case ADD_OR_GATE_2:
		pAct = new AddOR2(this);
		break;


	case ADD_NOR_GATE_3:
		pAct = new AddNOR3(this);
		break;


	case ADD_XNOR_GATE_2:
		pAct = new AddXNOR2(this);
		break;

	case ADD_XOR_GATE_2:
		pAct = new AddXOR2(this);
		break;

	case ADD_XOR_GATE_3:
		pAct = new AddXOR3(this);
		break;

	case ADD_NAND_GATE_2:
		pAct = new AddNAND2(this);
		break;

	case ADD_LED:
		pAct = new AddLED(this);
		break;

	case ADD_INV:
		pAct = new AddNOT(this);
		break;
	case ADD_Switch:
		pAct = new AddSWITCH(this);
		break;

	case ADD_CONNECTION:
		//TODO: Create AddConection Action here
		break;
	case Switch_Back:                     //hebaaaaaaaaaaa
		pAct = new SwitchBack(this);
		break;
	case EDIT_Label:                     //hebaaaaaaaaaaa
		pAct = new Edit_label(this);
		break;
	case DSN_MODE:
		pAct = new switchtodesign(this);
		break;
	case SIM_MODE:
		pAct = new switchtosim(this);
		break;
	case Add_Gate:
		pAct = new AddGate(this);
		break;
	case select_icon:
		pAct = new Select(this);
		break;
	case multi_select:
		pAct = new Multi_select(this);
		break;
	case unselect:
		pAct = new Unselect(this);
		break;

	case UNSELECTALL:           //A click on empty place in drawing area hebaaaaaaaaaaa
		pAct = new unselect_all(this);
		break;
	case UNDO:
		pAct = new undo(this);
		break;
	case REDO:
		pAct = new redo(this);
		break;
	case EXIT:
		///TODO: create ExitAction here
		break;
	}
	
	if(pAct)
	{
		pAct->Execute();
		//delete pAct;
		pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
	InputInterface->getWindowPtr()->SetPen(BLUE, 3);
	
	for (int i = 0; i < UI.width; i += 15)
	{
		for (int j = 90; j <UI.height - 50; j += 15)


			InputInterface->getWindowPtr()->DrawPixel(i, j);

	}
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->getlazy_d() == false)
			CompList[i]->Draw(OutputInterface);


	}

}

////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;
	
}
void ApplicationManager::fillmatrix()
{
	for (int i = 0; i <UI.height/15+1; i++)
		for (int j = 0; j <UI.width/15+1; j++)
		{

			blablabla[i][j].first = 0;
			blablabla[i][j].second = "empty";  //      
		}

	for (int i = 0; i <(UI.ToolBarHeight+10)/15+1; i++)
		for (int j = 0; j < UI.width / 15 + 1; j++)
		{
			blablabla[i][j].first = -5;
			blablabla[i][j].second = "toolbar";    
		}

	for (int i = (UI.height -UI.StatusBarHeight - 15) / 15 + 1; i <UI.height/15+1; i++)
		for (int j = 0; j < UI.width / 15 + 1; j++)
		{
			blablabla[i][j].first = -5;
			blablabla[i][j].second = "statusbar"; // statusbar    
		}

	
}
Component* ApplicationManager::find_component_with_specific_id(int component_id)
{
	int i;
	for ( i = 0; i < CompCount; i++)
	{
		if (CompList[i]->getid() == component_id)
			return CompList[i];
	}
	if (i >= CompCount)
		return  NULL;

}
void ApplicationManager::Lazy_DeleteComponent(int i, GraphicsInfo GInfo)
{
	cleaned = false;
	find_component_with_specific_id(i)->setlazy_d(true);
	find_component_with_specific_id(i)->delete_from_Matrix(GInfo);
}

void ApplicationManager::cleaning()
{
	cleaned = true;
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->getlazy_d() == true)
		{
			swap(CompList[i], CompList[CompCount - 1]);
			delete CompList[CompCount - 1];
			CompList[CompCount - 1] = NULL;
			CompCount--;
		}
	}
}

void  ApplicationManager::change_ALL_to_UnHI()
{
	for (int i = 0; i < CompCount; i++)
	{
		CompList[i]->change_to_UnHI();
	}
}
 
bool ApplicationManager::check_matrix(int cx, int cy)   //check almsahaa aly hadeef feha fadia wla laa
{
	cx /= 15; cy /= 15;
	bool t = true;
	for (int j = cy - 3; j <= cy + 2; j++) //50
	{
		for (int i = cx - 2; i <= cx + 2; i++)
		{
			if (j<0 || j>UI.height / 15 || i<1 || i>UI.width / 15)
				return false;
			if (blablabla[j][i].second != "empty")    // htrg3
			{
				t = false;
				break;
			}
		}
		if (!t)
			break;
	}
		/*
		for (int j = cy - 45; j < cy + 45; j++) //50
		{
			for (int i = cx - 45; i < cx + 45; i++)
			{
				if (j<0 || j>UI.height || i<0 || i>UI.width)
					return false;
				if (blablabla[j][i].second != "empty")
				{
					t = false;
					break;
				}
			}
			if (!t)
				break;
		}*/

		return t;
	
}