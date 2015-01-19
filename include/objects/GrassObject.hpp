/*
 * =====================================================================================
 *
 *       Filename:  GrassObject.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/10/2014 15:33:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef GRASSOBJECT_HPP_
#define GRASSOBJECT_HPP_

#include "Object.hpp"

class GrassObject : public Object {
	public:
		GrassObject(float x, float y, bool lowGrass = false);
		
		void onEvent(u8 event);
		
	private:
		bool m_lowGrass;
};

#endif // GRASSOBJECT_HPP_
