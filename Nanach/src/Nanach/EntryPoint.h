#pragma once

#ifdef CH_PLATFORM_WINDOWS
#include "Log.h"
extern Nanach::Application* Nanach::CreateApplication();

int main(int argc, char** argv)
{
	Nanach::Log::init();
	CH_CORE_ERROR("Initialized Log!");
	int a = 5;
	CH_INFO("Hello! Var={0}", a);

	auto app = Nanach::CreateApplication();
	app->Run();
	delete app;
}
#endif // CH_PLATFORM_WINDOWS

//this line is just test for git remote