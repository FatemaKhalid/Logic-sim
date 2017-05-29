#pragma once
#include "Component.h"
#include"..\GUI\Output.h"
#include "InputPin.h"
class LED :
	public Component
{
protected:
	InputPin m_InputPin;	//Input pin of the Gate
	

public:
	LED();
	LED(const GraphicsInfo & r_GfxInfo);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut);	//Draws 2-input gate
	virtual void updateMatrix(GraphicsInfo GInfo, int ID, string type);
	virtual void delete_from_Matrix(GraphicsInfo);
	virtual int GetOutPinStatus(); 	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual ~LED();
};

