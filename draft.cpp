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
struct SpriteAnimation {
	// ...
	
	std::vector<sf::Vector2i> positions;
}

class Sprite : public Image {
	public:
		Sprite(std::string filename, u16 frameWidth, u16 frameHeight) : Image(filename) {
			m_filename = filename;
			
			m_frameWidth = frameWidth;
			m_frameHeight = frameHeight;
		}
		
		~Sprite() {
		}
		
		void addAnimation(std::initializer_list<u16> frames, u16 delay) {
			// Add the animation
			
			// Fill 'positions' vector with sf::Vector2i(0, 0);
			// Because that's the default position
		}
		
		void addPosition(u16 anim, u16 animFrame, u16 x, u16 y) {
			m_animations[anim].positions[animFrame] = sf::Vector2i(x, y);
		}
		
		void drawFrame(s16 x, s16 y, u16 frame) {
			// Draw the frame
		}
		
		void drawPositionedFrame(s16 x, s16 y, u16 frame) {
			// Draw the frame with its position informations
		}
		
		void resetAnimation(u16 anim) {
			// ...
		}
		
		// ...
		
		void playAnimation(u16 anim) {
			// ...
			
			drawPositionedFrame(/*...*/);
		}
		
	private:
		std::vector<SpriteAnimation> m_animations;
};
