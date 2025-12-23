#include <vector>
#include <iostream>
#include "Player.hpp"

Player::Player(int n1, size_t idx)
	: value(n1)
	, swapped(false)
{
	bracket_idx.push_back(idx);
}

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
size_t Player::get_prev_bracket_idx() const
{
	if (bracket_idx.size() < 2)
		return bracket_idx[0];
	return bracket_idx[bracket_idx.size() - 2];
}

size_t Player::get_prev_bracket_idx(size_t current_bracket) const
{
	std::cout << "bracket at: " << current_bracket << "\n";
	if (current_bracket == 0)
		return bracket_idx[0];
	return bracket_idx[current_bracket - 1];
}
