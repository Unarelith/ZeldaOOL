/*
 * =====================================================================================
 *
 *       Filename:  draft.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/11/2014 21:08:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
class AudioPlayer {
	public:
		AudioPlayer();
		~AudioPlayer();
		
		void onInit();
		
		void playMusic(std::string name);
		
		void playSound(std::string name);
		
	private:
		std::map<std::string, std::shared_ptr<BackgroundMusic>> m_musics;
		std::map<std::string, std::shared_ptr<SoundEffect>> m_soundEffects;
};

class MapManager {
	public:
		MapManager();
		~MapManager();
		
		void onInit();
		
		Map &currentMap();
		
		Map &getMap(u16 x, u16 y, u16 area);
		
	private:
		Map &m_currentMap;
		
		std::vector<std::vector<std::shared_ptr<Map>>> m_maps;
};

class Game {
	public:
		Game();
		~Game();
		
		/* ... */
		
		static void initResources();
		
		static AudioPlayer &audioPlayer();
		static MapManager &mapManager();
		
	private:
		static AudioPlayer m_audioPlayer;
		static MapManager m_mapManager;
};

MapState::MapState() {
	/* ... */
	
	Game::initResources();
	
	Game::audioPlayer().playSound("gameStarted");
	
	Game::mapManager().currentMap()->load();
}

