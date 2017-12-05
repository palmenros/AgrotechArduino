/*
 * AutomatedModule.h
 *
 *  Created on: 2 dic. 2017
 *      Author: Pedro
 */

#ifndef AUTOMATEDMODULE_H_
#define AUTOMATEDMODULE_H_

class AutomatedModule {
protected:

	bool automatic = true;

public:

	/*Ideally, this methods should be pure virtual. They are not because they would create a v-table in every subclass, affecting performance*/
	void setup();
	void loop();

	void setAutomatic(bool automatic);
	bool isAutomatic() const;
};

#endif /* AUTOMATEDMODULE_H_ */
