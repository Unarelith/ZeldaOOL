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
		Player() : Character(/*...*/) {
			// ...
		}
		
		virtual ~Player() {
		}
		
		virtual void update() = 0;
		
		virtual void draw() = 0;
		
	private:
		// ...
};

class PlayerMoving : public Player {
	public:
		PlayerMoving() {
			// ...
		}
		
		~PlayerMoving() {
		}
		
		void update() {
			// Move the player
		}
		
		void draw() {
			// Draw movement animation
		}
};

class PlayerSwordAttack : public Player {
	public:
		PlayerSwordAttack() {
			// ...
		}
		
		~PlayerSwordAttack() {
		}
		
		void update() {
			// Update player and sword position
		}
		
		void draw() {
			// Draw player and sword
		}
		
	private:
		Sprite m_sword;
};

