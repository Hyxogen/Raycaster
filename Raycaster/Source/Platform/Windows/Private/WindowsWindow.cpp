#include "../Public/WindowsWindow.hpp"

namespace platform {
	namespace windows {

		LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

		WindowsWindow::WindowsWindow(unsigned int width, unsigned int height, const wchar_t* title) : m_HDC(nullptr), m_WindowHandle(nullptr), m_ShouldClose(false) {
			this->m_Width = width;
			this->m_Height = height;
			this->m_Title = title;
		}

		WindowsWindow::~WindowsWindow() {
			Close();
		}

		int WindowsWindow::Initialize() {
			if (m_HDC != nullptr || m_WindowHandle != nullptr)
				return 0;

			m_ShouldClose = false;
			if (!BuildWindow())
				return 0;
			return 1;
		}

		void WindowsWindow::Update() {
			MSG msg;
			while (PeekMessageW(&msg, m_WindowHandle, 0, 0, PM_REMOVE)) {
				TranslateMessage(&msg);
				DispatchMessageW(&msg);
			}
		}

		void WindowsWindow::Draw() {
			if (GetWindowHDC() == nullptr) return;
			SwapBuffers(GetWindowHDC());//Dit moet in theorie alleen gebeuren als het dual buffers zijn
		}

		void WindowsWindow::Close() {
			m_ShouldClose = true;
			ReleaseDC(m_WindowHandle, m_HDC);
			DestroyWindow(m_WindowHandle);
		}

		bool WindowsWindow::ShouldClose() const {
			return m_ShouldClose;
		}

		void WindowsWindow::SetVisibility(short visibility) {
			ShowWindow(m_WindowHandle, visibility);
		}

		int WindowsWindow::BuildWindow() {
			WNDCLASS wndClass = { };
			HINSTANCE instance = GetModuleHandleA(0);

			wndClass.lpfnWndProc = (WNDPROC)WindowProc; //TODO assign correct function
			wndClass.hInstance = instance;
			wndClass.lpszClassName = m_Title;

			RegisterClass(&wndClass);

			m_WindowHandle = CreateWindowEx(CS_OWNDC, m_Title, m_Title, WS_OVERLAPPEDWINDOW,
				CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
				NULL, NULL, instance, NULL);

			if (m_WindowHandle == 0)
				return 0;

			SetWindowLongPtr(m_WindowHandle, GWLP_USERDATA, (LONG_PTR)this);
			m_HDC = GetDC(m_WindowHandle);
			return 1;
		}

		LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
			if (uMsg == WM_CLOSE || uMsg == WM_QUIT || uMsg == WM_DESTROY) {
				WindowsWindow* window = reinterpret_cast<WindowsWindow*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
				window->Close();
				PostQuitMessage(0);
				return 0;
			}
			else {
				//Handle events?
			}
			return DefWindowProc(hwnd, uMsg, wParam, lParam);
		}
	}
}