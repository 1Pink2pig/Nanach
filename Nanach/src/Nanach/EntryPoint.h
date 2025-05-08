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

//this line is just test for git remote