#include "NOR3.h"
#include "..\ApplicationManager.h"

NOR3::NOR3(const GraphicsInfo &r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	settype("NOR3");
}


void NOR3::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	//Add you code here
}


// Function Draw
// Draws 2-input AND gate
void NOR3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNOR3(m_GfxInfo, getHI());
	pOut->Clear_string_from_D_A(m_GfxInfo.x1, m_GfxInfo.y1 - 20);
	pOut->Printstring_in_D_A(getlabel(), pOut, m_GfxInfo.x1, m_GfxInfo.y1 - 20); //mn 3ndy  hebaaaaa
	 //updateMatrix(m_GfxInfo, getid(), gettype());    //hebaaaaaaaaaa
}

void NOR3::updateMatrix(GraphicsInfo GInfo, int ID, string type) ///team 13    //zbt alid wltype hebaaaa
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

	ApplicationManager::blablabla[Cy - 1][Cx - 2].first = ID;
	ApplicationManager::blablabla[Cy - 1][Cx - 2].second = "c_u";
	ApplicationManager::blablabla[Cy][Cx - 2].first = ID;
	ApplicationManager::blablabla[Cy][Cx - 2].second = "c_m";

	ApplicationManager::blablabla[Cy + 1][Cx - 2].first = ID;
	ApplicationManager::blablabla[Cy + 1][Cx - 2].second = "c_l";


}
void NOR3::delete_from_Matrix(GraphicsInfo GInfo)
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
int NOR3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NOR3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
NOR3:: ~NOR3()
{
	delete_from_Matrix(m_GfxInfo);
}
