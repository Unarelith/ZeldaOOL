/*
 * =====================================================================================
 *
 *       Filename:  HealthComponent.hpp
 *
 *    Description:  
 *
 *        Created:  26/05/2015 12:22:17
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef HEALTHCOMPONENT_HPP_
#define HEALTHCOMPONENT_HPP_

#include "IntTypes.hpp"

class HealthComponent {
	public:
		HealthComponent(u8 _maxLife, u8 _life = 0)
			: maxLife(_maxLife), life(_life ? _life : _maxLife) {}
		
		void setLife(u8 newLife) { life = newLife > maxLife ? maxLife : newLife;}
		void addLife(u8 lifeAdded) { setLife(life + lifeAdded);}
		void removeLife(u8 lifeRemoved) { lifeRemoved > life ? setLife(0) : setLife(life - lifeRemoved);}
		
		u8 getLife() {return life;}
		u8 getMaxLife() {return maxLife;}
		
		bool isHurt = false;
		bool isDead = false;
		
	private:
		
		u8 maxLife = 0;
		u8 life = 0;
};

#endif // HEALTHCOMPONENT_HPP_
