#pragma once


#include "map.h"
#include <sfml/Graphics.hpp>


class Character : public sf::Drawable
{
protected:
    /**
     * the position of the character
     */
    sf::Vector2i m_pos;
    /**
     * the last position of the character (the one before the current one)
     */
    sf::Vector2i m_prevPos;
    
    /**
     * the original position of the character
     */
    sf::Vector2i m_originalPos;
    
    /**
     * the size of the character
     */
    float m_charSize;
    
    /**
     * the presents of the current move (from `m_prevPos` to `m_pos`)
     */
    double m_interval;
    
    /**
     * the position of the first cell in the board
     */
    sf::Vector2f m_gridOffset;

    /**
     * getting the sprite of the character
     * @return the sprite of the character
     */
    virtual sf::Sprite getSprite() const =0 ;

public:
    
    /**
     * num of cells to move each second 
     */
    static const int MOVEMENT_SPEED = 5;
    
    
    Character(sf::Vector2i pos,float charSize, sf::Vector2f gridOffset);

    /**
     * draw the character to the map
     * @param map the map to draw to
     */
    void drawOnMap(Map &map) const;

    /**
     * the character move algorithm
     * need to be implemented in sub-classes
     * @param map the algorithm may need the map
     */
    virtual void move(const Map &map) = 0;

    /**
     * draw the character on a map
     * @param map the map to draw on
     */
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    /**
     * get the character position
     * @return the character position
     */
    sf::Vector2i getPos() const;

    /**
     * get the character last (before the one its go into) position
     * @return the character position
     */
     sf::Vector2i getPrevPos() const;

    /**
     * reset the position of the character
     * (for example when the pacman interact with the ghosts)
     */
    void resetPos();

    /**
     * get the char of the character
     * need to be implemented in sub-classes
     * @return the char of the character
     */
    virtual char getChar() const = 0;

    /**
     * check if the move valid (for all character also checks for super)
     * @param map the map to check if the move valid
     * @param pos the position to check if its valid on the map
     * @return is the pos is a move that a regular character can do
     */
    bool isMoveValid(const Map &map, const sf::Vector2i &pos) const;

    /**
     * set the current interval of the character
     * interval is the the presents of the move that the character is doing
     * @param interval the new interval
     */
    void setInterval(float interval);
};

const char GHOST = '&';
const char PACMAN = 'a';
const char SUPER_PACMAN = '@';
