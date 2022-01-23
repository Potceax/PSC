#pragma once
#define ERROR_EXIT exit(0)
typedef int var;
typedef var* ptr;
typedef struct
{
	ptr buffer;
	var length;
}Array;

typedef struct
{
	Array* buffer;
	var rowLength;
	var ColumnLength;
}Array_2D;

