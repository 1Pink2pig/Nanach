#pragma once
#include "Nanach/Layer.h"
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
		float m_Time = 0.0f;
	};


}
