#pragma once

#include <windows.h>
#include "../../../Engine/Util/Assert.hpp"
#include "../../../Engine/Core/Public/Application.hpp"

core::Application* CreateApplication();

int main(int argc, char** argv) {
	ASSERT(0); //If this gets triggered, you haven't setup the project as a windows window project or you are using an unsupported platform
	return -1;
}

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR pCmdLine, _In_ int nCmdShow) {
	core::Application* application = CreateApplication();
	application->Run();
	delete application;
	return 1;
}