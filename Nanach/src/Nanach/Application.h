#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "Nanach/Events/ApplicationEvent.h"
#include "Nanach/Log.h"
#include "Nanach/Window.h"

namespace Nanach
{

	class NANACH_API Application
	{
	public:
		Application();
		virtual ~Application();
		void OnEvent(Event& e);
		void Run();
	private:

		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}



