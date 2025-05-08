#include "Nanach/Nanach.h"
class Sandbox : public Nanach::Application
{	
public:
	Sandbox()
	{
	}
	~Sandbox()
	{
	}
};

Nanach::Application* Nanach::CreateApplication()
{
	return new Sandbox();
}