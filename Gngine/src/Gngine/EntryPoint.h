#pragma once

#ifdef GE_PLATFORM_WINDOWS

extern Gngine::Application* Gngine::CreateApplication();

	int main(int argc, char** argv) {
		printf("Hello guys\n");
		Gngine::Log::init();
		GE_CORE_WARN("Core Logger");
		GE_CORE_INFO("Client Logger");
		auto app = Gngine::CreateApplication();
		app->run();
		delete app;

		return 0;
	}

#endif // GE_PLATFORM_WINDOWS
