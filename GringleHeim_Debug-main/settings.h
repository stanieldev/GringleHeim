#pragma once
#ifndef SETTINGS_H
#define SETTINGS_H



#include <SFML/Graphics.hpp>



struct Settings {
    // Window Stuff
    const unsigned short screenResolutionX = 1280; // In Pixels
    const unsigned short screenResolutionY = 720;  // In Pixels
    const unsigned short FramesPerSecond = 60;     // In FPS

    const unsigned short renderDistanceX = screenResolutionX / 64 + 1;    // In Blocks
    const unsigned short renderDistanceY = screenResolutionY / 64 + 1;    // In Blocks
    const sf::Time oneFrame = sf::milliseconds(1000.0 / FramesPerSecond); // Time For 1 Frame
};



#endif // SETTINGS_H