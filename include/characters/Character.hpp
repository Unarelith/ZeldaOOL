/*
 * =====================================================================================
 *
 *       Filename:  Character.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/12/2014 01:24:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include "MapObject.hpp"
#include "Movable.hpp"

class Character : public MapObject, public Movable {
	public:
		Character();
		Character(std::string filename, u16 frameWidth = 16, u16 frameHeight = 16);
		virtual ~Character();
		
		void load(std::string filename, u16 frameWidth = 16, u16 frameHeight = 16);
		
		bool inCollisionWith(Character &character);
};

#endif // CHARACTER_HPP_
