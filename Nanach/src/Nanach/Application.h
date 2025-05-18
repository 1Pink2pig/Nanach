#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "Nanach/Events/ApplicationEvent.h"
#include "Nanach/Log.h"
#include "Nanach/Window.h"
#include "Nanach/LayerStack.h"

namespace Nanach
{

	class NANACH_API Application
	{
	public:
		Application();
		virtual ~Application();
		void OnEvent(Event& e);
		void Run();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:

		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}



