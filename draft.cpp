/*
 * =====================================================================================
 *
 *       Filename:  draft.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  27/08/2014 22:57:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
class Player : public Character {
	public:
		Player() : Character(/* ... */) {
			// ...
		}
		
		virtual ~Player() {
		}
		
		virtual void update() = 0;
		
		virtual void draw() = 0;
};


class PlayerPushing : public Player {
	public:
		PlayerPushing() {
		}
		
		~PlayerPushing() {
		}
		
		void update() {
			
		}
		
		void draw() {
			playAnimation(m_x, m_y, m_direction + 4);
			
			EffectManager::drawEffects(this);
		}
}

