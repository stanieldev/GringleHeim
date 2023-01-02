#include <iostream>
#include <fstream>
#include "player.h"



Player::Player() {
	//load_save();
	load_player_atlas();
};

Player::~Player() {
	//save_data();
	//unload_player_atlas();
};


/*
void Player::load_save() { // Loads previous save data

	// Default initialization
	std::ifstream _file("save\\player.dat");
	std::vector<int> _data;
	std::string _line;

	// If the save file exists, load the file to _data
	// If not, load default from settings.h
	if (_file.fail()) {
		_data = PLAYER_DEFAULT_SAVE;
	}
	else {
		while (_file) {
			std::getline(_file, _line);
			_data.push_back(stoi(_line));
		};
	};

	// Send data to correct parameters
	int pos_x = _data.at(0);
	int pos_y = _data.at(1);
	int vel_x = _data.at(2);
	int vel_y = _data.at(3);
};

void Player::save_data() { // Overwrites previous save data

	// Default initialization
	std::ofstream _file ("save\\player.dat", std::ofstream::trunc);
	std::vector<int> _data = { pos_x, pos_y, vel_x, vel_y };
	std::string _string = "";

	// Generate data string
	for (int value : _data) {
		_string += std::to_string(value) + "\n";
	};

	// Save and close file
	_file << _string;
	_file.close();
};*/



void Player::load_player_atlas() {

	// Default initialization
	sf::Texture _texture;
	const std::vector<std::string> _files = {
		"1.png", 
		"2.png", 
		"3.png"
	};

	// Add textures to atlas
	for (std::string _frame : _files) {
		_texture.loadFromFile("assets\\player\\" + _frame);
		player_atlas.push_back(_texture);
	};
};

void Player::unload_player_atlas() {
	player_atlas.clear();
	std::cout << "unloaded p atlas" << std::endl;
};



void Player::move() {

	// Keyboard controls
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		pos_y -= vel_y;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		pos_x -= vel_x;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		pos_y += vel_y;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		pos_x += vel_x;

	// Debug console
	std::cout << pos_x << " " << pos_y << std::endl;
}
