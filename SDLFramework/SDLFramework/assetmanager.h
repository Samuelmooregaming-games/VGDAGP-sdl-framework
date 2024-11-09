#pragma once
#include "graphics.h"
#include <map>

namespace SDLFramework {
	class AssetManager {
	public:
		static AssetManager* Instance();
		static void Release();

		SDL_Texture* GetTexture(std::string filename, bool managed = false);

		void DestroyTexture(SDL_Texture* texture);

	private:
		AssetManager();
		~AssetManager();

		void UnloadTexture(SDL_Texture* texture);

		static AssetManager* sInstance;

		std::map<std::string, SDL_Texture*> mTextures;
		std::map<SDL_Texture*, unsigned> mTextureRefCount;
	};


}