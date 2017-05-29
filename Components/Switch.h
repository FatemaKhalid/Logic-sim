#pragma once
#include"..\GUI\Output.h"
#include "OutputPin.h"
#include "Component.h"

class Switch :
	public Component
{
protected:
	OutputPin m_OutputPin;	//The switch output pin
	
public:
	//Switch( int r_FanOut);	////////////////msh 3arfa a3ml zero construtor wla no    
	/////TODOOOOO:
	///// fn. to turn on and off the switch
	Switch(const GraphicsInfo &r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut);	 //Draws 2-input gate
	virtual void updateMatrix(GraphicsInfo GInfo, int ID, string type);
	virtual void delete_from_Matrix(GraphicsInfo);
	virtual int GetOutPinStatus();
	int GetInputPinStatus(int n);	//returns status of outputpin if LED, return -1
	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual ~Switch();
	


};

