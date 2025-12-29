#include <vector>
#include <iostream>

#include "Player.hpp"

Player::Player()
	: value(0)
	, swapped(false) {}

Player::Player(const Player& other)
	: value(other.value)
	, adversary(other.adversary)
	, bracket_idx(other.bracket_idx)
	, swapped(other.swapped) {}

Player& Player::operator=(const Player& other)
{
	value = other.value;
	adversary = other.adversary;
	bracket_idx = other.bracket_idx;
	swapped = other.swapped;
	return *this;
}

Player::~Player(){}

Player::Player(int n1)
	: value(n1)
	, swapped(false) {}

Player::Player(Player* other, size_t idx)
	: value(other->value)
	, swapped(other->swapped)
{
	bracket_idx = other->bracket_idx;
	bracket_idx.push_back(idx);
}

void Player::set_adversary(Player* opponent)
{
	adversary = opponent;
}

void Player::register_idx(size_t idx)
{
	bracket_idx.push_back(idx);
}

size_t Player::get_prev_bracket_idx(size_t current_bracket) const
{
	if (current_bracket == 0)
		return bracket_idx[0];
	return bracket_idx[current_bracket - 1];
}

std::ostream& operator<<(std::ostream& os, const Player& p)
{
	os << "Value: " << p.value << " ";
	os << "Adversary: ";
	if (p.adversary)
		os << p.adversary->value << " ";
	else
		os << "NULL" << " ";
	os << "Swapped: " << std::boolalpha << p.swapped << " ";
	os << "Idxs: ";
	for (size_t i = 0; i < p.bracket_idx.size(); ++i)
		os << "[" << i << "]" << p.bracket_idx[i] << " ";
	os << "\n";
	return os;
}
