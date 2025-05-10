#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "Nanach/Events/ApplicationEvent.h"
#include "Nanach/Log.h"

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



