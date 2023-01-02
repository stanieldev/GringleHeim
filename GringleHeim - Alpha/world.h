#pragma once
#ifndef WORLD_H
#define WORLD_H


#include <SFML/Graphics.hpp>


class World {
public:
    int tile_size = 32; // The size of tiles rendered in pixels
    std::vector<sf::Texture> floor_atlas;
    std::vector<sf::Texture> wall_atlas;
    
    World();
    ~World();

private:
    // Initialization
    void load_floor_atlas(); // Load floor textures
    void load_wall_atlas(); // Load floor textures

    // Deconstruction
    void unload_floor_atlas(); // Unload floor textures
    void unload_wall_atlas(); // Unload floor textures
};


#endif // WORLD_H