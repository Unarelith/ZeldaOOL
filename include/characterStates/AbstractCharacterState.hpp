/*
 * =====================================================================================
 *
 *       Filename:  AbstractCharacterState.hpp
 *
 *    Description:  
 *
 *        Created:  19/01/2015 18:26:39
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
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
