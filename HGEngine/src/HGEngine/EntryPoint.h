#pragma once

#ifdef HGE_PLATFORM_WINDOWS

extern HGEngine::Application* HGEngine::CreateApplication();

int main(int argc, char** argv)
{
	auto app = HGEngine::CreateApplication();

	app->Run();

	delete app;
}

#endif