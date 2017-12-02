/*
 * AutomatedModule.cpp
 *
 *  Created on: 2 dic. 2017
 *      Author: Pedro
 */

#include "AutomatedModule.h"

void AutomatedModule::setAutomatic(bool automatic)
{
	this->automatic = automatic;
}

bool AutomatedModule::isAutomatic() const
{
	return automatic;
}
