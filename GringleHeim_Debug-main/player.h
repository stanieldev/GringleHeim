#pragma once
#ifndef PLAYER_H
#define PLAYER_H



#include <vector>
#include <SFML/Graphics.hpp>



class Player{
    // Player Position
    int posX;   // In Pixels
    int blockX; // In Blocks
    int pixelX; // In Pixels
    int posY;   // In Pixels
    int blockY; // In Blocks
    int pixelY; // In Pixels

    // Texture Atlases
    std::vector<sf::Texture> playerAtlas;

    // Texture Loaders
    void loadPlayerAtlas();

    // Player Movement Function
    void move();

    // Render Player On Screen
    void displayPlayer(sf::RenderWindow& window, Player player, int frame);

    Player(int playerPosX = 640, int playerPosY = 360);
};



#endif // PLAYER_H