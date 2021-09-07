#pragma once

#include <windows.h>
#include "../../../Engine/IO/Public/Window.hpp"

namespace platform {
	namespace windows {

		class WindowsWindow : public io::Window {
		protected:
			HWND m_WindowHandle;
			HDC m_HDC;
			bool m_ShouldClose;

		public:
			WindowsWindow(unsigned int width, unsigned int height, const wchar_t* title);

			virtual ~WindowsWindow();

			/*
			Will fail if trying to initialze an already initialized window
			*/
			int Initialize();

			void Update();

			void Draw();

			void Close();

			bool ShouldClose() const;

			void SetVisibility(short visibility);

			inline HWND GetWindowHandle() const { return m_WindowHandle; }
			
			inline HDC GetWindowHDC() const { return m_HDC; }

		protected:
			int BuildWindow();
		};
	}
}