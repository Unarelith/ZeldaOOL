/*
 * =====================================================================================
 *
 *       Filename:  PlayerBehaviour.hpp
 *
 *    Description:  
 *
 *        Created:  02/05/2015 12:40:36
 *
 *         Author:  Quentin Bazin, <gnidmoo@gmail.com>
 *
 * =====================================================================================
 */
#ifndef PLAYERBEHAVIOUR_HPP_
#define PLAYERBEHAVIOUR_HPP_

#include "Behaviour.hpp"

class PlayerBehaviour : public Behaviour{
	public:
		PlayerBehaviour() : Behaviour("Standing") {}
		
		void action(SceneObject &object) override;
		
		void updateSprite(SceneObject &object);
		
	private:
		SceneObject *m_sword = nullptr;
};

#endif // PLAYERBEHAVIOUR_HPP_
