// External Libaries
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>

// Internal Libaries
#include "player.h"
#include "settings.h"
#include "world.h"





int main() {
    // Classes Declaration
    Settings settings; // Game Settings
    Player player;     // Playable Character
    World world;       // World Of Play

    // SFML Stuff
    sf::RenderWindow window(sf::VideoMode(settings.screenResolutionX, settings.screenResolutionY), "Gringly", sf::Style::Default);
    sf::Clock clock;      // IDK Gage Said I Should Have This
    sf::Time elapsedTime; // Elapsed Time Between Frames
    sf::Event event;      // Event Detection

    // Run Game Window
    while (window.isOpen()) {

        // Checks If Window Is Closed
        while (window.pollEvent(event))
            if(event.type == sf::Event::Closed)
                window.close();
                
        // Game Running Loop
        elapsedTime = clock.getElapsedTime();
        if (elapsedTime.asMilliseconds() >= settings.oneFrame.asMilliseconds() && window.hasFocus()) {
            player.move(); // Moves Player
            world.genWorld(window, player); // Generates World Around Player
            player.displayPlayer(window, player, 1);
            
            window.display(); // Displays Final Generated World
            clock.restart();  // Resets Duration Clock
        }

    }

    return 0;
}