#include "assetmanager.h"

namespace SDLFramework {
	AssetManager* AssetManager::sInstance = nullptr;

	AssetManager* AssetManager::Instance() {
		if (sInstance == nullptr) {
			sInstance = new AssetManager();
		}
		return sInstance;
	}
	void AssetManager::Release() {
		delete sInstance;
	sInstance = nullptr;
		}

	AssetManager::AssetManager() {

	}
	
	AssetManager::~AssetManager() {
		for (auto tex : mTextures) {
			if (tex.second != nullptr) {
				SDL_DestroyTexture(tex.second);
			}
		}

		mTextures.clear();
	}

	SDL_Texture* AssetManager::GetTexture(std::string fileName, bool managed) {
		std::string fullpath = SDL_GetBasePath();
		fullpath.append("Assets/" + fileName);

		if (mTextures[fullpath] == nullptr) {
			mTextures[fullpath] = Graphics::Instance()->LoadTexture(fullpath);
		}

		if (mTextures[fullpath] != nullptr && managed) {
			mTextureRefCount[mTextures[fullpath]] += 1;
		}

		return mTextures[fullpath];
	}
	void AssetManager::DestroyTexture(SDL_Texture* texture) {
		std::map<SDL_Texture*, unsigned>::iterator it = mTextureRefCount.find(texture);
	
		if (it != mTextureRefCount.end()) {
			it->second -= 1;
			if (it->second == 0) {
				UnloadTexture(it->first);
				mTextureRefCount.erase(it->first);
			}
		}
		else {
			UnloadTexture(texture);
		}
	}

	void AssetManager::UnloadTexture(SDL_Texture* texture) {
		bool found = false;
		std::string key;
		std::map<std::string, SDL_Texture*>::iterator it;
	
		for (it = mTextures.begin(); it != mTextures.end() && !found; it++) {
			if ((found = it->second == texture)) {
				SDL_DestroyTexture(it->second);
				key = it->first;
			}
		}
		if (found) {
			mTextures.erase(key);
		}
	}
}