#pragma once
#ifndef WORLD_H
#define WORLD_H

#include <SFML/Graphics.hpp>
#include "player.h"



struct World {
    // Texture Atlases
    std::vector<sf::Texture> floorAtlas;
    std::vector<sf::Texture> wallAtlas;

    // Texture Loaders
    void loadFloorAtlas();
    void loadWallAtlas();

    // World Generator
    void genWorld(sf::RenderWindow& window, Player player);

    

    World();
};



#endif // WORLD_H