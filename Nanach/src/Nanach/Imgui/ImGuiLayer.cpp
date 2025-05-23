#include "chpch.h"
#include "ImGuiLayer.h"

#include "Nanach/Platform/OpenGL/ImGuiOpenGLRenderer.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Nanach/Application.h"
namespace Nanach {
	ImGuiLayer::ImGuiLayer()
		: Layer("ImGuiLayer")
	{
	}
	ImGuiLayer::~ImGuiLayer()
	{
	}
	void ImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

		ImGui_ImplOpenGL3_Init("#version 410");
		
	}
	void ImGuiLayer::OnDetach()
	{
		
	}
	void ImGuiLayer::OnUpdate()
	{
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

		float time = (float)glfwGetTime();
		io.DeltaTime = m_Time > 0.0 ? (time - m_Time) : (1.0f / 60.0f);
		m_Time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}
	void ImGuiLayer::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<MouseButtonPressedEvent>(CH_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonPressedEvent));
		dispatcher.Dispatch<MouseButtonReleasedEvent>(CH_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonReleasedEvent));
		dispatcher.Dispatch<MouseMovedEvent>(CH_BIND_EVENT_FN(ImGuiLayer::OnMouseMovedEvent));
		dispatcher.Dispatch<MouseScrolledEvent>(CH_BIND_EVENT_FN(ImGuiLayer::OnMouseScrolledEvent));
		dispatcher.Dispatch<KeyPressedEvent>(CH_BIND_EVENT_FN(ImGuiLayer::OnKeyPressedEvent));
		dispatcher.Dispatch<KeyReleasedEvent>(CH_BIND_EVENT_FN(ImGuiLayer::OnKeyReleasedEvent));
		dispatcher.Dispatch<KeyTypedEvent>(CH_BIND_EVENT_FN(ImGuiLayer::OnKeyTypedEvent));
		dispatcher.Dispatch<WindowResizeEvent>(CH_BIND_EVENT_FN(ImGuiLayer::OnWindowResizeEvent));
	}
	void ImGuiLayer::Begin()
	{
	}
	void ImGuiLayer::End()
	{
	}

	ImGuiKey ImGuiLayer::GlfwKeyToImGuiKey(KeyCode keyCode)
	{
		// notice:now this function accept KeyCode defined in Nanach means not use GLFW keycode
		// assume KeyCode and GLFW keycode values are compatible

		switch (keyCode)
		{
		case Key::Space: return ImGuiKey_Space;
		case Key::Apostrophe: return ImGuiKey_Apostrophe;
		case Key::Comma: return ImGuiKey_Comma;
		case Key::Minus: return ImGuiKey_Minus;
		case Key::Period: return ImGuiKey_Period;
		case Key::Slash: return ImGuiKey_Slash;
		case Key::D0: return ImGuiKey_0;
		case Key::D1: return ImGuiKey_1;
		case Key::D2: return ImGuiKey_2;
		case Key::D3: return ImGuiKey_3;
		case Key::D4: return ImGuiKey_4;
		case Key::D5: return ImGuiKey_5;
		case Key::D6: return ImGuiKey_6;
		case Key::D7: return ImGuiKey_7;
		case Key::D8: return ImGuiKey_8;
		case Key::D9: return ImGuiKey_9;
		case Key::Semicolon: return ImGuiKey_Semicolon;
		case Key::Equal: return ImGuiKey_Equal;
		case Key::A: return ImGuiKey_A;
		case Key::B: return ImGuiKey_B;
		case Key::C: return ImGuiKey_C;
		case Key::D: return ImGuiKey_D;
		case Key::E: return ImGuiKey_E;
		case Key::F: return ImGuiKey_F;
		case Key::G: return ImGuiKey_G;
		case Key::H: return ImGuiKey_H;
		case Key::I: return ImGuiKey_I;
		case Key::J: return ImGuiKey_J;
		case Key::K: return ImGuiKey_K;
		case Key::L: return ImGuiKey_L;
		case Key::M: return ImGuiKey_M;
		case Key::N: return ImGuiKey_N;
		case Key::O: return ImGuiKey_O;
		case Key::P: return ImGuiKey_P;
		case Key::Q: return ImGuiKey_Q;
		case Key::R: return ImGuiKey_R;
		case Key::S: return ImGuiKey_S;
		case Key::T: return ImGuiKey_T;
		case Key::U: return ImGuiKey_U;
		case Key::V: return ImGuiKey_V;
		case Key::W: return ImGuiKey_W;
		case Key::X: return ImGuiKey_X;
		case Key::Y: return ImGuiKey_Y;
		case Key::Z: return ImGuiKey_Z;
		case Key::LeftBracket: return ImGuiKey_LeftBracket;
		case Key::Backslash: return ImGuiKey_Backslash;
		case Key::RightBracket: return ImGuiKey_RightBracket;
		case Key::GraveAccent: return ImGuiKey_GraveAccent;
		case Key::Escape: return ImGuiKey_Escape;
		case Key::Enter: return ImGuiKey_Enter;
		case Key::Tab: return ImGuiKey_Tab;
		case Key::Backspace: return ImGuiKey_Backspace;
		case Key::Insert: return ImGuiKey_Insert;
		case Key::Delete: return ImGuiKey_Delete;
		case Key::Right: return ImGuiKey_RightArrow;
		case Key::Left: return ImGuiKey_LeftArrow;
		case Key::Down: return ImGuiKey_DownArrow;
		case Key::Up: return ImGuiKey_UpArrow;
		case Key::PageUp: return ImGuiKey_PageUp;
		case Key::PageDown: return ImGuiKey_PageDown;
		case Key::Home: return ImGuiKey_Home;
		case Key::End: return ImGuiKey_End;
		case Key::CapsLock: return ImGuiKey_CapsLock;
		case Key::ScrollLock: return ImGuiKey_ScrollLock;
		case Key::NumLock: return ImGuiKey_NumLock;
		case Key::PrintScreen: return ImGuiKey_PrintScreen;
		case Key::Pause: return ImGuiKey_Pause;
		case Key::F1: return ImGuiKey_F1;
		case Key::F2: return ImGuiKey_F2;
		case Key::F3: return ImGuiKey_F3;
		case Key::F4: return ImGuiKey_F4;
		case Key::F5: return ImGuiKey_F5;
		case Key::F6: return ImGuiKey_F6;
		case Key::F7: return ImGuiKey_F7;
		case Key::F8: return ImGuiKey_F8;
		case Key::F9: return ImGuiKey_F9;
		case Key::F10: return ImGuiKey_F10;
		case Key::F11: return ImGuiKey_F11;
		case Key::F12: return ImGuiKey_F12;
		case Key::KP0: return ImGuiKey_Keypad0;
		case Key::KP1: return ImGuiKey_Keypad1;
		case Key::KP2: return ImGuiKey_Keypad2;
		case Key::KP3: return ImGuiKey_Keypad3;
		case Key::KP4: return ImGuiKey_Keypad4;
		case Key::KP5: return ImGuiKey_Keypad5;
		case Key::KP6: return ImGuiKey_Keypad6;
		case Key::KP7: return ImGuiKey_Keypad7;
		case Key::KP8: return ImGuiKey_Keypad8;
		case Key::KP9: return ImGuiKey_Keypad9;
		case Key::KPDecimal: return ImGuiKey_KeypadDecimal;
		case Key::KPDivide: return ImGuiKey_KeypadDivide;
		case Key::KPMultiply: return ImGuiKey_KeypadMultiply;
		case Key::KPSubtract: return ImGuiKey_KeypadSubtract;
		case Key::KPAdd: return ImGuiKey_KeypadAdd;
		case Key::KPEnter: return ImGuiKey_KeypadEnter;
		case Key::KPEqual: return ImGuiKey_KeypadEqual;
		case Key::LeftShift: return ImGuiKey_LeftShift;
		case Key::LeftControl: return ImGuiKey_LeftCtrl;
		case Key::LeftAlt: return ImGuiKey_LeftAlt;
		case Key::LeftSuper: return ImGuiKey_LeftSuper;
		case Key::RightShift: return ImGuiKey_RightShift;
		case Key::RightControl: return ImGuiKey_RightCtrl;
		case Key::RightAlt: return ImGuiKey_RightAlt;
		case Key::RightSuper: return ImGuiKey_RightSuper;
		case Key::Menu: return ImGuiKey_Menu;
		default: return ImGuiKey_None;
		}
	}

	bool ImGuiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = true;
		return false;
	}

	bool ImGuiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = false;
		return false;
	}

	bool ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(e.GetX(), e.GetY());
		return false;
	}
	bool ImGuiLayer::OnMouseScrolledEvent(MouseScrolledEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheel += e.GetYOffset();
		io.MouseWheelH += e.GetXOffset();
		return false;
	}
	bool ImGuiLayer::OnKeyPressedEvent(KeyPressedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		CH_INFO("Key pressed in ImGui");
		ImGuiKey key = GlfwKeyToImGuiKey(e.GetKeyCode());

		if (key != ImGuiKey_None) 
		{
			io.AddKeyEvent(key, true);
		}
		UpdateImGuiModifiers(e.GetKeyCode(), false);
		return false;
	}
	bool ImGuiLayer::OnKeyReleasedEvent(KeyReleasedEvent& e)
	{	
		ImGuiIO& io = ImGui::GetIO();
		ImGuiKey key = GlfwKeyToImGuiKey(e.GetKeyCode());
		if (key != ImGuiKey_None) 
		{
			io.AddKeyEvent(key, false);
		}
		UpdateImGuiModifiers(e.GetKeyCode(), false);
		return false;
	}
	bool ImGuiLayer::OnKeyTypedEvent(KeyTypedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		int keycode = e.GetKeyCode();
		if (keycode > 0 && keycode < 0x10000)
		{
			io.AddInputCharacter((unsigned short)keycode);
		}
		return false;
	}
	bool ImGuiLayer::OnWindowResizeEvent(WindowResizeEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(e.GetWidth(), e.GetHeight());
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		glViewport(0, 0, e.GetWidth(), e.GetHeight());
		return false;
	}
	void ImGuiLayer::UpdateImGuiModifiers(KeyCode keyCode, bool pressed)
	{
		ImGuiIO& io = ImGui::GetIO();
		switch (keyCode) {
		case Key::LeftControl:
		case Key::RightControl:
			io.KeyCtrl = pressed;
			break;
		case Key::LeftShift:
		case Key::RightShift:
			io.KeyShift = pressed;
			break;
		case Key::LeftAlt:
		case Key::RightAlt:
			io.KeyAlt = pressed;
			break;
		case Key::LeftSuper:
		case Key::RightSuper:
			io.KeySuper = pressed;
			break;
		}
	}
}	