#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"          
#include "..\GUI\Output.h"

//Base class for classes Gate, Switch, and LED.
class Component
{
private:
	string m_Label;
	////hebaaa 
    int id;
	static int last_id;
	string type;
	bool HI; //feryal needed for select action////////////////////
	bool lazy_deleted;
protected:
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
	//GraphicsInfo label_GfxInfo;  ////The parameters required to draw a label hebaaaaaaaaaaaa
public:
	Component(const GraphicsInfo &r_GfxInfo,string type="notype",string label=""); //zwdt altype,label
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut) = 0;	//for each component to Draw itself
	virtual void updateMatrix(GraphicsInfo,  int, string) = 0; //team 13 ///HEBAAA RG3THAAAAAAAAA
	virtual void delete_from_Matrix(GraphicsInfo) = 0; //team 13 ///HEBAAA RG3THAAAAAAAA
	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1
	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.
	virtual void change_to_HI(); //feryal 
	virtual bool getHI();
	int getid();
	string gettype();
	void settype(string t);
	string getlabel();
	void edit_label(string label);
	GraphicsInfo getm_GfxInfo();
	virtual void change_to_UnHI(); //feryal 
	void setlazy_d(bool l);
	bool getlazy_d();
	
	Component();	
	
	//Destructor must be virtual
	virtual ~Component();

};

#endif
