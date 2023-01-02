#include "world.h"
#include <iostream>



World::World() {
    load_floor_atlas();
    load_wall_atlas();
};

World::~World() {
    //unload_floor_atlas();
    //unload_wall_atlas();
};



void World::load_floor_atlas() {

    // Default initialization
    sf::Texture _texture;
    const std::vector<std::string> _files = {
        "grassssssssss.png",
        "woody.png",
        "stonislav.png",
        "marble_time.png"
    };

    // Add textures to atlas
    for (std::string _frame : _files) {
        _texture.loadFromFile("assets\\floor\\" + _frame);
        floor_atlas.push_back(_texture);
    };
};

void World::unload_floor_atlas() {
    floor_atlas.clear();
    std::cout << "unloaded f atlas" << std::endl;
};



void World::load_wall_atlas() {

    // Default initialization
    sf::Texture _texture;
    const std::vector<std::string> _files = {
        ".png",     // 0000
        "L.png",    // 0001
        "R.png",    // 0010
        "RL.png",   // 0011
        "D.png",    // 0100
        "DL.png",   // 0101
        "DR.png",   // 0110
        "DRL.png",  // 0111
        "U.png",    // 1000
        "UL.png",   // 1001
        "UR.png",   // 1010
        "URL.png",  // 1011
        "UD.png",   // 1100
        "UDL.png",  // 1101
        "UDR.png",  // 1110
        "UDRL.png", // 1111
    };

    // Add textures to atlas
    for (std::string _frame : _files) {
        _texture.loadFromFile("assets\\wall\\" + _frame);
        wall_atlas.push_back(_texture);
    };
};

void World::unload_wall_atlas() {
    wall_atlas.clear();
    std::cout << "unloaded w atlas" << std::endl;
};
