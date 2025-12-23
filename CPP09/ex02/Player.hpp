#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <cstddef>

struct Player
{
	int value;
	Player* adversary;
	std::vector<size_t> bracket_idx;
	bool swapped;

	Player(int n1, size_t idx);
	Player(Player* other, size_t idx);

	void set_adversary(Player* opponent);
	void register_idx(size_t idx);
	size_t get_prev_bracket_idx() const;
	size_t get_prev_bracket_idx(size_t current_bracket) const;
};

#endif // PLAYER_HPP
