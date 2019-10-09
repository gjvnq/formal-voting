#include "basics.h"

void clear_ballots(ballot_set *set) {
	for (int i=0; i < set->len; i++) {
		set->ballots[i].id = 0;
		set->ballots[i].top = 0;
		for (int j=0; j < MAX_CANDIDATES+1; j++) {
			set->ballots[i].sel[j] = 0;
		}
	}
}
