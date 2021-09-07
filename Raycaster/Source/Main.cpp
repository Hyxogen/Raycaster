#include "Engine\Core\Public\EntryPoint.hpp"
#include "Engine\Core\Public\Application.hpp"


class TestApplication : public core::Application {

public:
	TestApplication() {

	}

	~TestApplication() {

	}
};

core::Application* CreateApplication() {
	return new TestApplication();
}