#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"
#include<stack>

#include<string>     //mn 3ndy
//#include "UI_INFO_H"
//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	int CompCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)

	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface


	

						   //ta3deeeeeeeel heba w feryal
	bool cleaned;       //m3nah ano fe 7agat fe al lesta m3molha lazy deletion wlsa mtms7tsh wla la



public:
	//ta3deeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeel 
	stack<Action*>Actual_A;
	stack<Action*>REDO_A;
	static std::pair<int, std::string> blablabla[UI.height/15+1][UI.width/15+1];
	ApplicationManager(); //constructor
	void fillmatrix();
    void change_ALL_to_UnHI();    //  hebaaaa
	int e7sas(int x, int y)     //3shan trg3ly hna mwgod eeh  hebaaaaaaaaaaa
	{
		return ApplicationManager::blablabla[y][x].first;
			
	}
	void Lazy_DeleteComponent(int i, GraphicsInfo GInfo);
	void cleaning();

	bool getcleaned()
	{
		return cleaned;
	}
	void setcleaned(bool t)
	{
		cleaned = t;
	}
	bool check_matrix(int cx, int cy);
	int getcopmcount()
	{
		return CompCount;
	}
	//Reads the required action from the user and returns the corresponding action type         
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);

	Component* find_component_with_specific_id(int component_id);   ///hebaaaaaaaaaa
	//destructor
	~ApplicationManager();
};

#endif