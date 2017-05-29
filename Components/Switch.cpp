#include "Switch.h"
#include "..\ApplicationManager.h"
//class Component;

Switch::Switch(const GraphicsInfo &r_GfxInfo, int r_FanOut):m_OutputPin(r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	settype("Switch");
	
}

         
void Switch::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	//Add you code here
}


// Function Draw
// Draws Switch
void Switch::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawSWITCHOFF(m_GfxInfo, getHI());		///temporarly fatema
	pOut->Clear_string_from_D_A(m_GfxInfo.x1, m_GfxInfo.y1 - 20);
	pOut->Printstring_in_D_A(getlabel(), pOut, m_GfxInfo.x1, m_GfxInfo.y1 - 20);
}

#include"..\ApplicationManager.h"

void Switch::updateMatrix(GraphicsInfo GInfo, int ID, string type) ///team 13    //zbt alid wltype hebaaaa
{
	int Cx = GInfo.x1 + UI.AND2_Width / 2;
	int Cy = GInfo.y1 + UI.AND2_Height / 2;

	Cy = Cy / 15;
	Cx = Cx / 15;
	for (int i = Cy - 3; i <= Cy + 2; i++)
	{
		for (int j = Cx - 2; j <= Cx + 2; j++)
		{
			ApplicationManager::blablabla[i][j].first = ID;
			ApplicationManager::blablabla[i][j].second = type;
		}
	}




	ApplicationManager::blablabla[Cy - 3][Cx - 1].first = -1;                            // the text in the matrix
	ApplicationManager::blablabla[Cy - 3][Cx - 1].second = "label";
	ApplicationManager::blablabla[Cy - 3][Cx].first = -1;
	ApplicationManager::blablabla[Cy - 3][Cx].second = "label";
	ApplicationManager::blablabla[Cy - 3][Cx + 1].first = -1;
	ApplicationManager::blablabla[Cy - 3][Cx + 1].second = "label";

	ApplicationManager::blablabla[Cy][Cx + 2].first = ID;                            //the connections in the matrix 
	ApplicationManager::blablabla[Cy][Cx + 2].second = "c_o";

	
	ApplicationManager::blablabla[Cy][Cx - 2].first = ID;
	ApplicationManager::blablabla[Cy][Cx - 2].second = "c_m";

	
}
void Switch::delete_from_Matrix(GraphicsInfo GInfo)
{
	int Cx = GInfo.x1 + UI.AND2_Width / 2;
	int Cy = GInfo.y1 + UI.AND2_Height / 2;

	Cy = Cy / 15;
	Cx = Cx / 15;
	for (int i = Cy - 3; i <= Cy + 2; i++)
	{
		for (int j = Cx - 2; j <= Cx + 2; j++)
		{
			ApplicationManager::blablabla[i][j].first = 0;
			ApplicationManager::blablabla[i][j].second = "empty";
		}
	}

}

//returns status of outputpin
int Switch::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}

void Switch::setInputPinStatus(int n, STATUS s)
{
	/////////l fn. by3ml 7aga fe mkan tane w inherated 3'sb 3ne :'(
	OutputPin m_InputPin(3);
	m_InputPin.setStatus(s);
}
//returns status of Inputpin #n
int Switch::GetInputPinStatus(int n)	
{
	return -1;	//n starts from 1 but array index starts from 0.
}

Switch:: ~Switch()
{
	delete_from_Matrix(m_GfxInfo);
}
