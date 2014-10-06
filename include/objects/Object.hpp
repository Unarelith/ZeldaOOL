/*
 * =====================================================================================
 *
 *       Filename:  Object.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/09/2014 20:59:08
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <map>
#include <functional>

#include "Entity.hpp"

class Object : public Entity {
	public:
		Object(float x, float y);
		~Object();
		
		void setEventAction(u8 event, std::function<void(Object *)> action);
		
		void onEvent(u8 event);
		
	private:
		std::map<u8, std::function<void(Object *)>> m_actions;
};

#endif // OBJECT_HPP_
