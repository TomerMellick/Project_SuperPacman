#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "result.h"
#include "map.h"
#include "StaticObject.h"



class Board : public sf::Drawable
{
private:
    /**
     * the map of the board
     */
    Map m_map;
    
    /**
     * the position of the first cell in the board
     */
    sf::Vector2f m_gridOffset;
    
    /**
     * the size of the board
     */
    sf::Vector2f m_gridSize;
    
    /**
     * number of cookies in the board
     */
    int m_numOfCookies;
    
    /**
     * good chars for map as null-terminated array
     */
    static const StaticObject MAP_CHARS[NUM_OF_STATIC_OBJECTS];

    /**
     * draw the board to the window
     * @param target what to draw
     * @param states 
     */
    virtual void draw(sf::RenderTarget& target, 
                      sf::RenderStates states) const override;
    /**
    * checks if the given char is one that composites a map
    * @param c - char to check
    * @return true/false
    */
    bool isMapChar(char c) const;

    /**
     * opens the closest door to the given position
     * @param pos - position from which we measure distance
     */
    void openClosestDoor(sf::Vector2i pos);

public:

    Board(const Map &startingMap, sf::Vector2f gridSize, sf::Vector2f gridOffset);

    /**
     * updates the board according to the interaction with pacman
     * @param pacmanPos - the cell which interacts with pacman
     * @return the char that was in the given pos
     */
    char updateBoard(const sf::Vector2i &pacmanPos);

    /**
     * map getter
     * @return Map copy
     */
    Map getMap() const;

    /***
     * getting the number of cookies left on the board
     * @return int
     */
    int getNumOfCookies() const;

    /**
     * add time to the board's map
     * @param time the time to add
     */
    void addTime(sf::Time time);
};


