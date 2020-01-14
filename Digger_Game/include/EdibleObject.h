#pragma once
#include "Object.h"
#include "MovableObject.h"
#include "StupidMonster.h"
#include "SmartMonster.h"
#include "Digger.h"

class EdibleObject : public Object
{
public:

	//virtual ~EdibleObject() = 0 {}

	
	bool is_eaten()const;
	void eat();
	virtual void eatWithUpdate(Data& data) = 0;
protected:

	bool  m_eaten = false;
};

