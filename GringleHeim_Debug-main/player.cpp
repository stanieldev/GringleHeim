#include "player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "settings.h"
#include "world.h"





Settings defaultStuff;


/*
bool collision(int X, int Y, char direction) {
    // Map & Texture Indexing
    int mapX, mapY;
    int posX, posY;

    mapX =  (X / 32) + (defaultStuff.renderDistanceX);
    mapY =  (Y / 32) + (defaultStuff.renderDistanceY);
    posX = -(X % 32) + (defaultStuff.screenResolutionX / 2) + 16;
    posY = -(Y % 32) + (defaultStuff.screenResolutionY / 2) + 16;

    switch (direction) {
    case 'L':
        if (wallArray[mapY][mapX - 1] == 1)
            return true;
        break;
    case 'R':
        if (wallArray[mapY][mapX + 1] == 1)
            return true;
        break;
    case 'D':
        if (wallArray[mapY - 1][mapX] == 1)
            return true;
        break;
    case 'U':
        if (wallArray[mapY + 1][mapX] == 1)
            return true;
        break;
    }
    return false;
}

*/








// Player Data Structure Object
Player::Player(int playerPosX, int playerPosY) {
    //playerPosX -= 16 * (defaultStuff.screenResolutionX / 32);
    //playerPosY -= 16 * (defaultStuff.screenResolutionY / 32);

    posX   = playerPosX;      // In Pixels
    blockX = playerPosX / 32; // In Blocks
    pixelX = playerPosX % 32; // In Pixels

    posY   = playerPosY;      // In Pixels
    blockY = playerPosY / 32; // In Blocks
    pixelY = playerPosY % 32; // In Pixels

    loadPlayerAtlas();
}



void Player::loadPlayerAtlas() {
    sf::Texture tempTexture;
    std::vector<std::string> playerMap = {
        "player1.png", // 1
        "player2.png", // 2
        "player3.png"  // 3
    };
    for (unsigned int i = 0; i < playerMap.size(); i++) {
        tempTexture.loadFromFile("assets\\npcs\\" + playerMap.at(i));
        playerAtlas.push_back(tempTexture);
    }
}



// Player Movement Controller
void Player::move() {
    const int playerVelX = 4; // In Pixels
    const int playerVelY = 4; // In Pixels


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) // Move Up
        posY -= playerVelY;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) // Move Left
        posX -= playerVelX;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) // Move Down
        posY += playerVelY;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // Move Right
        posX += playerVelX;
        

    // Update Player Block & Pixel
    blockX = posX / 32; // In Blocks
    pixelX = posX % 32; // In Pixels
    blockY = posY / 32; // In Blocks
    pixelY = posY % 32; // In Pixels

    std::cout << blockX << ' ' << blockY << std::endl;
}



// Display Player
void Player::displayPlayer(sf::RenderWindow& window, Player player, int frame) {
    // Default Temporary Sprite
    sf::Sprite tempSprite;

    tempSprite.setTexture(playerAtlas.at(frame));
    tempSprite.setPosition(posX, posY);
    window.draw(tempSprite);
}



