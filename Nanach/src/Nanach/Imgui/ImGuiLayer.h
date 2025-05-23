#pragma once
#include "Nanach/Layer.h"
#include "Nanach/Events/KeyEvent.h"
#include "Nanach/Events/MouseEvent.h"
#include "Nanach/Events/ApplicationEvent.h"
#include "imgui.h"

namespace Nanach {
	class NANACH_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() override;
		void OnAttach() override;
		void OnDetach() override;
		void OnUpdate() override;
		void OnEvent(Event& event) override;
		void Begin();
		void End();
	private:
		ImGuiKey GlfwKeyToImGuiKey(KeyCode keyCode);
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnWindowResizeEvent(WindowResizeEvent& e);
		void UpdateImGuiModifiers(KeyCode keyCode, bool pressed);
	private:
		float m_Time = 0.0f;
	};


}
