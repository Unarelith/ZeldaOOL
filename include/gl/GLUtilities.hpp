/*
 * =====================================================================================
 *
 *       Filename:  GLUtilities.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/12/2014 06:30:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef GLUTILITIES_HPP_
#define GLUTILITIES_HPP_

#include <SFML/OpenGL.hpp>

namespace GLUtilities {
	void setupPerspective(GLdouble fovY, GLdouble aspect, GLdouble zNear, GLdouble zFar);
	void lookAt(GLdouble eyex, GLdouble eyey, GLdouble eyez, GLdouble centerx, GLdouble centery, GLdouble centerz, GLdouble upx, GLdouble upy, GLdouble upz);
}

#endif // GLUTILITIES_HPP_
