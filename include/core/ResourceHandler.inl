/*
 * =====================================================================================
 *
 *       Filename:  ResourceHandler.inl
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/12/2014 03:13:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
template<>
void ResourceHandler::add<sf::Texture, std::string>(std::string name, std::string path) {
	m_resources[name] = std::shared_ptr<void>(new sf::Texture);
	get<sf::Texture>(name).loadFromFile(path);
}

template<>
void ResourceHandler::add<AnimatedMap, std::string, std::string>(std::string name, std::string path, std::string tileset) {
	m_resources[name] = std::shared_ptr<void>(new AnimatedMap(path, tileset));
	get<AnimatedMap>(name).updateTiles();
}

