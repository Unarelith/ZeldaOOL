/*
 * =====================================================================================
 *
 *       Filename:  BattlerState.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  19/10/2014 21:03:48
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef BATTLERSTATE_HPP_
#define BATTLERSTATE_HPP_

#include "Battler.hpp"
#include "CharacterState.hpp"

class BattlerState : public CharacterState {
	public:
		BattlerState(Battler *battler);
		virtual ~BattlerState();
		
		virtual void update() = 0;
		
		virtual void draw() = 0;
		
	protected:
		Battler *m_battler;
};

#endif // BATTLERSTATE_HPP_
