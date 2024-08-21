#pragma once

#ifdef HGE_PLATFORM_WINDOWS

extern HGEngine::Application* HGEngine::CreateApplication();

int main(int argc, char** argv)
{
	HGEngine::Log::Init();
	HGE_CORE_ERROR("Error in core engine.");
	HGE_INFO("Application info msg.");
	


	auto app = HGEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif