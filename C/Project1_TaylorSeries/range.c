#include "range.h"

int range_contain(Range* range, double point)
{
	// Check left range.
	if (!range->start.is_infinity)
	{
		if (range->start.value > point)
			return 0;
		if (!range->start.is_range_closed && range->start.value == point)
			return 0;
	}

	// Check rigth range.
	if (!range->end.is_infinity)
	{
		if (range->end.value < point)
			return 0;
		if (!range->end.is_range_closed && range->end.value == point)
			return 0;
	}

	return 1;
}