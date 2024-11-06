#pragma once
#include <SDL.h>
#include<iostream>

namespace SDLFramework {
	class Graphics {
	public:
		static const int SCREEN_WIDTH = 600;
		static const int SCREEN_HEIGHT = 800;

		static Graphics* Instance();
		//handle releasing (uninitializing) memory
		static void Release();
		static bool Initialized();

		void ClearBackBuffer();
		void Render();

		Graphics();
		~Graphics();

		bool Init();

	private:
		//hold 1 instance of graphics class
		static Graphics* sInstance;
		static bool sInitialized;
		SDL_Window* mwindow = nullptr;
		SDL_Renderer* mrenderer = nullptr;
	};
}