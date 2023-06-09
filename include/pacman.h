#pragma once

#include "character.h"
#include <SFML/Graphics.hpp>

class Pacman : public Character
{
private:

    int m_super;
    int m_health;
    sf::Vector2i m_direction;



public:

    /**
     * get the sprite of the pacman (or super pacman)
     * @return sprite of the pacman (not include position or scale)
     */
    sf::Sprite getSprite() const override;

    Pacman(sf::Vector2i position,float charSize, sf::Vector2f gridOffset);

    /**
     * the health of the pacman
     * @return 
     */
    int getHealth() const;

    /**
     * dec the health by 1
     */
    void decHealth();

    /**
     * mov the pacman by the map
     * @param map the map
     */
    void move(const Map &map) override;

    /**
     * get the char (a or @)
     * @return 'a' or '@'
     */
    char getChar() const override;

    /**
     * set the pacman to super mode
     */
    void setSuper();

    /**
     * set the direction of the pacman
     * @param key the key that pressed
     */
    void setDirection(sf::Keyboard::Key key);

    /**
     * check if the pacman is super
     * @return is pacman super
     */
    bool isSuper() const;

    /**
     * inc the life by 1
     */
    void incLife();
};