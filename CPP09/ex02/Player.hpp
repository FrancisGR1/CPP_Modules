#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <cstddef>
#include <ostream>

struct Player
{
	Player();
	Player(int n1);
	Player(Player* other, size_t idx);
	Player(const Player& other);
	Player& operator=(const Player& other);
	~Player();

	int value;
	Player* adversary;
	Player* rank;
	std::vector<size_t> bracket_idx;
	bool swapped;

	void set_adversary(Player* opponent);
	void register_idx(size_t idx);
	size_t get_prev_bracket_idx(size_t current_bracket) const;
};

std::ostream& operator<<(std::ostream& os, const Player& p);

#endif // PLAYER_HPP
