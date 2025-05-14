
//namespace Gngine {
//	__declspec(dllimport) void Print();
//}

#include <Gngine.h>
class Sandbox : public Gngine::Application {
public:
	Sandbox() {

	}
	~Sandbox() {

	}
};

Gngine::Application* Gngine::CreateApplication() {
	return new Sandbox();
}