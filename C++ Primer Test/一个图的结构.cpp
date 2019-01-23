#include <iostream>
using namespace std;

typedef enum { find, notfind } Status;

struct node
{
	int x, y;
	Status status;
	node *prev, *succ;
};

int main_tu()
{
	return 0;
}