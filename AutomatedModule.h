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

	virtual void setup() = 0;
	virtual void loop() = 0;

	virtual ~AutomatedModule() = default;

	void setAutomatic(bool automatic);
	bool isAutomatic() const;
};

#endif /* AUTOMATEDMODULE_H_ */
