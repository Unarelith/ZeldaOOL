/*
 * =====================================================================================
 *
 *       Filename:  AbstractCharacterState.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  19/01/2015 18:26:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef ABSTRACTCHARACTERSTATE_HPP_
#define ABSTRACTCHARACTERSTATE_HPP_

class AbstractCharacterState {
	public:
		virtual ~AbstractCharacterState() = default;
		
		virtual void update() = 0;
		
		virtual void render() = 0;
		
		virtual bool canStartMapTransition() const { return false; }
};

#endif // ABSTRACTCHARACTERSTATE_HPP_
