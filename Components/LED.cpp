#include "LED.h"
#include "..\ApplicationManager.h"


LED::LED()
{
}




LED::LED(const GraphicsInfo &r_GfxInfo) 
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	settype("LED");
}


void LED::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	//Add you code here
}


// Function Draw
// Draws LED
void LED::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawLED(m_GfxInfo, getHI());
	pOut->Clear_string_from_D_A(m_GfxInfo.x1, m_GfxInfo.y1 - 20);
	pOut->Printstring_in_D_A(getlabel(), pOut, m_GfxInfo.x1, m_GfxInfo.y1 - 20);
}


void LED::updateMatrix(GraphicsInfo GInfo, int ID, string type) ///team 13    //zbt alid wltype hebaaaa
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

	ApplicationManager::blablabla[Cy+2][Cx].first = ID;                            //the connections in the matrix 
	ApplicationManager::blablabla[Cy+2][Cx ].second = "c_l";

}
void LED::delete_from_Matrix(GraphicsInfo GInfo)
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
int LED::GetOutPinStatus()
{
	return -1;
}


//returns status of Inputpin #n
int LED::GetInputPinStatus(int n)
{
	return m_InputPin.getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void LED::setInputPinStatus(int n, STATUS s)
{
	m_InputPin.setStatus(s);
}
LED:: ~LED()
{
	delete_from_Matrix(m_GfxInfo);
}
