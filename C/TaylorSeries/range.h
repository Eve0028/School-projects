#pragma once

typedef struct RangePoint
{
	const char* name;
	double value;
	int is_infinity;
	int is_range_closed;
}RangePoint;

typedef struct Range
{
	RangePoint start;
	RangePoint end;
}Range;

// Returns 1 if the given point is within the range of the selected formula,
// otherwise returns 0.
int range_contain(Range* range, double point);
