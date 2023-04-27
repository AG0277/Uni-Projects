#pragma once

#include <stack>
class States
{
private:
protected:

public:
	States();
	~States();

	virtual	void update() = 0;
	virtual void render() = 0;
};

