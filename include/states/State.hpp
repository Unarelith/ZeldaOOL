/*
 * =====================================================================================
 *
 *       Filename:  State.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/07/2014 13:54:14
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef STATE_HPP_
#define STATE_HPP_

class State {
	public:
		State(State *parent = nullptr);
		virtual ~State();
		
		virtual void update() = 0;
		
		virtual void render() = 0;
		
		enum Type {
			Type_Map
		};
		
	protected:
		Type m_type;
		
		State *m_parent;
};

#endif // STATE_HPP_
