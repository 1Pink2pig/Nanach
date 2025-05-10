#include "chpch.h"
#include "Application.h"
namespace Nanach
{

	Application::Application()
	{
	}
	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 1080);
		CH_TRACE(e.ToString());
		while (true);
	}

}