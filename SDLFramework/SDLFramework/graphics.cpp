#include "Graphics.h"

namespace SDLFramework {
	//how static members in a class are initialized
	//ones not wanted to be constants
	Graphics* Graphics::sInstance = nullptr;
	bool Graphics::sInitialized = false;

	// where this class made singleton
	Graphics* Graphics::Instance() {
		if (sInstance == nullptr) {
			//if not new graphics instance
			sInstance = new Graphics();
		}
		//returns graphics instance after checking if there is one
		return sInstance;
	}

	void Graphics::Release() {
		delete sInstance;
		sInstance = nullptr;
		sInitialized = false;
	}

	bool Graphics::Initialized() {
		return sInitialized;
	}


	void Graphics::ClearBackBuffer() {
		SDL_RenderClear(mrenderer);
	}

	void Graphics::Render() {
		SDL_RenderPresent(mrenderer);
	}
}