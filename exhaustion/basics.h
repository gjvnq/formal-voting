#pragma once
#ifndef BASICS
#define BASICS
#include <stdio.h>

#define MAX_CANDIDATES 5
#define MAX_BALLOTS 100

typedef enum {Yes = 1, No = -1, Unsure = 0} trinary;


typedef struct {
	int id, top;
	int sel[MAX_CANDIDATES+1];
} ballot;

typedef struct {
	ballot *ballots;
	int len;
} ballot_set;

void clear_ballots(ballot_set *set);
ballot_set clone_ballots(ballot_set *set);

// Criteria
trinary is_monotonic(ballot_set *set, int winner);
trinary is_condorcet(ballot_set *set, int winner);
trinary is_majority(ballot_set *set, int winner);
trinary is_condorcet_loser(ballot_set *set, int winner);
trinary is_majority_loser(ballot_set *set, int winner);
trinary is_mutual_majority(ballot_set *set, int winner);
trinary is_smith(ballot_set *set, int winner);
trinary is_isda(ballot_set *set, int winner);
trinary is_liia(ballot_set *set, int winner);
trinary is_clone_independent(ballot_set *set, int winner);
trinary is_reverse_symetrical(ballot_set *set, int winner);
trinary is_smith(ballot_set *set, int winner);

// Methods (return winner id or negative if there is no winner)
int one_turn(ballot_set *set); // also known as first past the post or plural
int two_turn(ballot_set *set);
int rankerd_pairs(ballot_set *set);
int schulze(ballot_set *set);
int borda(ballot_set *set);

// Less important voting systems that I don't care so much about
int alternative_smith(ballot_set *set);
int alternative_schwartz(ballot_set *set);
int kemeny_young(ballot_set *set);
int copeland(ballot_set *set);
int nanson(ballot_set *set);
int instant_runoff(ballot_set *set);
int baldwin(ballot_set *set);
int bucklin(ballot_set *set);
int contingent(ballot_set *set);
int coombs(ballot_set *set);
int minimax(ballot_set *set);
int anti_plurality(ballot_set *set);
int sri_lankan_contingent(ballot_set *set);
int supplementary_voting(ballot_set *set);
int dodgson(ballot_set *set);

#endif // BASICS
