/*
 * =====================================================================================
 *
 *       Filename:  ICharacterState.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/10/2014 18:25:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef ICHARACTERSTATE_HPP_
#define ICHARACTERSTATE_HPP_

#include <functional>

class ICharacterState {
	public:
		virtual ~ICharacterState() {}
		
		virtual void update() = 0;
		
		virtual void render() = 0;
		
		virtual bool canStartMapTransition() = 0;
		
		typedef std::function<ICharacterState*(void)> StateTransition;
};

#endif // ICHARACTERSTATE_HPP_
