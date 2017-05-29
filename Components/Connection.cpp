#include "Connection.h"

Connection::Connection(const GraphicsInfo &r_GfxInfo, OutputPin *pSrcPin,InputPin *pDstPin):Component(r_GfxInfo)	
	
{
	SrcPin = pSrcPin;
	DstPin = pDstPin;
}
void Connection::setSourcePin(OutputPin *pSrcPin)
{	SrcPin = pSrcPin;	}

OutputPin* Connection::getSourcePin()
{	return SrcPin;	}


void Connection::setDestPin(InputPin *pDstPin)
{	DstPin = pDstPin;	}

InputPin* Connection::getDestPin()
{	return DstPin;	}


void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus((STATUS)SrcPin->getStatus());
}

void Connection::Draw(Output* pOut)
{
	pOut->DrawConnection(m_GfxInfo);
}

int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}

void updateMatrix(vector<pair<int, int >>path)
{
	int i= path.size() - 1;
	if (path[i].first == path[i - 1].first) //check 3ala awel point 
	{
		ApplicationManager::blablabla[path[i].second][path[i].first].second = "cv";
		ApplicationManager::blablabla[path[i-1].second][path[i-1].first].second = "cv";
	}
	else
	{
		ApplicationManager::blablabla[path[i].second][path[i].first].second = "ch";
		ApplicationManager::blablabla[path[i - 1].second][path[i - 1].first].second = "ch";
	}
	for (int j = path.size()-2; j > 0; j--)
	{
		if (path[j].first == path[j - 1].first)
		{
			if (ApplicationManager::blablabla[path[j].second][path[j].first].second == "ch")
			{
				ApplicationManager::blablabla[path[j].second][path[j].first].second = "cd";

			}

			if (ApplicationManager::blablabla[path[j-1].second][path[j-1].first].second == "ch")
				ApplicationManager::blablabla[path[j-1].second][path[j-1].first].second = "cd";
			else ApplicationManager::blablabla[path[j-1].second][path[j-1].first].second = "cv";
		}
		else
		{
			if (ApplicationManager::blablabla[path[j].second][path[j].first].second == "cv")
			{
				ApplicationManager::blablabla[path[j].second][path[j].first].second = "cd";

			}

			if (ApplicationManager::blablabla[path[j - 1].second][path[j - 1].first].second == "cv")
				ApplicationManager::blablabla[path[j - 1].second][path[j - 1].first].second = "cd";
			else ApplicationManager::blablabla[path[j - 1].second][path[j - 1].first].second = "ch";





		}
	}
}
