/*
 * =====================================================================================
 *
 *       Filename:  draft2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  28/08/2014 01:25:00
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
			
			m_currentState = nullptr;
			
			setState(new StandingState());
		}
		
		~Player() {
		}
		
		void update() {
			m_currentState->update();
		}
		
		void draw() {
			m_currentState->draw();
		}
		
		// ...
		
		State *setState(State *state) {
			if(m_currentState) delete m_currentState;
			m_currentState = state;
			m_currentState->update();
		}
		
	private:
		// ...
		
		State *m_currentState;
};

class State {
	public:
		State() {
			m_player = CharacterManager::player;
		}
		
		virtual ~State() {
		}
		
		virtual void update() = 0;
		
		virtual void draw() = 0;
		
	private:
		Player &m_player;
};

class StandingState : public State {
	public:
		StandingState() {
		}
		
		~StandingState() {
		}
		
		void update() {
			// Sword key and state changement to sword
			
			// Arrow keys and state changement to moving
		}
		
		void draw() {
			m_player.drawFrame(player.x(), player.y(), player.direction());
			
			EffectManager::drawEffects(&player);
		}
};

class MovingState : public PlayerState {
	public:
		MovingState() {
		}
		
		~MovingState() {
		}
		
		void update() {
			// Keys...
			
			m_player.setX(player.x() + player.vx());
			m_player.setY(player.y() + player.vy());
			
			m_player.setVX(0);
			m_player.setVY(0);
		}
		
		void draw() {
		}
};

class SwordState: public PlayerState {
	public:
		SwordState() {
			m_lastUpdatedAnimFrame = {-1, -1, -1, -1};
		}
		
		~SwordState() {
		}
		
		void update() {
			m_sword.update(Sword::State::Swinging);
			
			// /!\ DANGER ZONE /!\ \\
			//		Here find a way to move link
			//		forward, then back to his
			//		previous position
			// /!\ END OF DANGER ZONE /!\ \\
			
			if(m_lastUpdatedAnimFrame != m_sword.animationCurrentFrame(m_player.direction())) {
			}
		}
		
		void draw() {
			m_player.playAnimation(m_player.x(), m_player.y(), m_player.direction() + 8);
			
			EffectManager::drawEffects(&m_player);
			
			m_sword.draw();
		}
		
	private:
		s16 m_lastUpdatedAnimFrame[4];
		
		Sword m_sword;
};

