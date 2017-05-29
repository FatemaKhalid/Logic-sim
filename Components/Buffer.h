#pragma once
#include "Gate.h"

class Buffer :
	public Gate
{

protected:
	InputPin m_InputPin;	//Array of input pins of the Gate
	OutputPin m_OutputPin;	//The Gate output pin
public:

	Buffer(const GraphicsInfo &r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut);	//Draws 2-input gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.

	void updateMatrix(GraphicsInfo GInfo, int ID, string type);

	void delete_from_Matrix(GraphicsInfo GInfo);

};

