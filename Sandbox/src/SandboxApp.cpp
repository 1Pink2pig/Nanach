#include "Nanach/Nanach.h"
class ExampleLayer : public Nanach::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		CH_CORE_INFO("ExampleLayer::Update");
	}

	void OnEvent(Nanach::Event& event) override
	{
		CH_CORE_INFO("{0}", event.ToString());
	}

};

class Sandbox : public Nanach::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}
	~Sandbox()
	{
	}
};

Nanach::Application* Nanach::CreateApplication()
{
	return new Sandbox();
}