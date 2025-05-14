#pragma once

#ifdef GE_PLATFORM_WINDOWS

extern Gngine::Application* Gngine::CreateApplication();

	int main(int argc, char** argv) {
		printf("Hello guys\n");
		auto app = Gngine::CreateApplication();
		app->run();
		delete app;

		return 0;
	}

#endif // GE_PLATFORM_WINDOWS
