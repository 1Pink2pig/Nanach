#pragma once
#include "Core.h"
namespace Nanach 
{

class NANACH_API Application
{
public:
	Application();
	virtual ~Application();
	void Run();
};

// To be defined in CLIENT
Application* CreateApplication();

}
	


