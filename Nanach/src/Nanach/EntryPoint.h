#pragma once

#ifdef CH_PLATFORM_WINDOWS

extern Nanach::Application* Nanach::CreateApplication();

int main(int argc,char **argv)
{
	auto app = Nanach::CreateApplication();
	app->Run();
	delete app;
}
#endif // CH_PLATFORM_WINDOWS
