#pragma once

#include <iostream>
#include <string>
using namespace std;

class ObjetoBase {
public:
	virtual ~ObjetoBase();
	virtual string toString() const = 0;
};

ostream& operator<<(ostream&, const ObjetoBase&);