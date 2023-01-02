#pragma once
#ifndef PLAYER_H
#define PLAYER_H


#include <SFML/Graphics.hpp>


struct Player {
public:
	int pos_x = 640; // In pixels
	int pos_y = 480; // In pixels
	int vel_x = 4; // In pixels per frame
	int vel_y = 4; // In pixels per frame
	std::vector<sf::Texture> player_atlas; // Player textures

	Player();
	~Player();

	void move(); // Player movement controller

private:
	// Initialization
	void load_save(); // Load previous save file
	void load_player_atlas(); // Load player textures

	// Deconstruction
	void save_data(); // Save current data to file
	void unload_player_atlas(); // Unloads player textures from memory
};


#endif // PLAYER_H