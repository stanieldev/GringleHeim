#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "player.h"
#include "world.h"
#include <iostream>





const unsigned short floor_array[9][16] = {
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
    {2,0,2,2,2,2,2,2,2,0,0,0,0,0,0,2},
    {2,0,2,1,1,1,1,1,2,0,0,0,0,0,0,2},
    {2,0,2,1,1,1,1,1,2,0,0,0,0,0,0,2},
    {2,0,2,1,1,1,1,1,2,0,0,0,0,0,0,2},
    {2,0,2,1,1,1,1,1,2,0,0,0,0,0,0,2},
    {2,0,2,1,1,1,1,1,2,0,0,0,0,0,0,2},
    {2,0,2,2,2,2,2,2,2,0,0,0,0,0,0,2}
};
const unsigned short wall_array[9][16] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};




const int SCREEN_X = 1280; // In pixels
const int SCREEN_Y = 720;  // In pixels
const int FPS = 60;        // In FPS
const sf::Time ONE_FRAME = sf::milliseconds(1000.0 / FPS); // Time for 1 frame



void render_world(sf::RenderWindow& window, World world, Player player) {

    // Block sprite
    sf::Sprite block_sprite;
    block_sprite.setScale(world.tile_size / 16.0f, world.tile_size / 16.0f);

    // World Map
    const int map_index_max_x = 16;
    const int map_index_max_y = 9; 
    
    // Indexing
    int map_index_x;
    int map_index_y;
    int block_pos_x;
    int block_pos_y;

    // Block indexing
    int block_render_x = SCREEN_X / (world.tile_size * 2) + 1;
    int block_render_y = SCREEN_Y / (world.tile_size * 2) + 1;
    int wall_connect_index;
    
    // Player block and pixel offset
    int player_block_x = player.pos_x / world.tile_size;
    int player_block_y = player.pos_y / world.tile_size;
    int player_pixel_x = player.pos_x % world.tile_size;
    int player_pixel_y = player.pos_y % world.tile_size;

    // Make Background Default Sky Color
    window.clear(sf::Color::Cyan);


    // Loops For All Blocks On Screen
    for (int i = -block_render_x; i < block_render_x; i++) {
        for (int j = -block_render_y; j < block_render_y; j++) {

            // Finding Indeces
            map_index_x = player_block_x + i;
            map_index_y = player_block_y + (block_render_y + j);
            block_pos_x = -player_pixel_x + (SCREEN_X / 2) + (i * world.tile_size);
            block_pos_y = -player_pixel_y + (SCREEN_Y / 2) + (j * world.tile_size);

            // Draw Block(s)
            if (map_index_x > -1 && map_index_x < map_index_max_x && map_index_y > -1 && map_index_y < map_index_max_y) { // If Within Bounds Of Map Array

                if (wall_array[map_index_y][map_index_x] == 1) { // If Wall
                    wall_connect_index = 15;
                    if (wall_array[map_index_y][map_index_x - 1] == 1) { wall_connect_index -= 1; }
                    if (wall_array[map_index_y][map_index_x + 1] == 1) { wall_connect_index -= 2; }
                    if (wall_array[map_index_y + 1][map_index_x] == 1) { wall_connect_index -= 4; }
                    if (wall_array[map_index_y - 1][map_index_x] == 1) { wall_connect_index -= 8; }
                    block_sprite.setTexture(world.wall_atlas.at(wall_connect_index));
                }
                else                            // If Not Wall
                    block_sprite.setTexture(world.floor_atlas.at(floor_array[map_index_y][map_index_x]));

                block_sprite.setPosition(block_pos_x, block_pos_y);
                window.draw(block_sprite);

            }
        }
    }
}



void render_player(sf::RenderWindow& window, Player player, int frame) {
    sf::Sprite sprite;
    sprite.setTexture(player.player_atlas.at(frame));
    sprite.setPosition(player.pos_x, player.pos_y);
    window.draw(sprite);
}



int main() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_X, SCREEN_Y), "Gringly", sf::Style::Default);
    sf::Clock clock;
    sf::Time elapsed_time;
    sf::Event event;
    Player player;
    World world;

    // Run Game Window
    while (window.isOpen()) {

        // Checks If Window Is Closed
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        // Game Running Loop
        elapsed_time = clock.getElapsedTime();
        if (elapsed_time.asMilliseconds() >= ONE_FRAME.asMilliseconds() && window.hasFocus()) {

            // Move player
            player.move();

            // Render the world
            render_world(window, world, player);

            // Render the player
            render_player(window, player, 1);

            window.display(); // Displays Final Generated World
            clock.restart();  // Resets Duration Clock
        }

    }

    return 0;
}




