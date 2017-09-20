#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define len(X) (sizeof(X) / sizeof(X[0]))

int const states[] = {0, 0, 0, 0, 0, 0, 0, 0};

typedef struct _node {
	int value;
	struct _node *next;
	struct _node *prev;
} node_t, *list_t;

list_t cons(int value, list_t next, list_t prev)
{
	list_t node = calloc(1, sizeof(node_t));
	node->value = value;
	node->next = next;
	node->prev = prev;

	return node;
}

list_t make_railway()
{
	int i;
	list_t wagons = NULL;
	list_t last = NULL;
	list_t first = NULL;

	wagons = cons(states[len(states) - 1], NULL, NULL);
	first = wagons;

	for (i = len(states) - 2; i >= 0; i--) {
		list_t aux = cons(states[i], NULL, wagons);
		wagons->next = aux;
		wagons = aux;
	}

	// make circular
	wagons->next = first;
	first->prev = wagons;

	return first;
}

void print(list_t wagons)
{
	int i = 0;
	list_t aux = wagons;

	while (1) {
		printf("[%d]\n", aux->value);

		if ((++i) % len(states) == 0)
			break;
		aux = aux->next;
	}
}

int count(list_t wagons, int start_wagon)
{
	int count = 0;
	int offset_from_beginning = 0;
	int i;

	// the idea is to have only one ptr
	// i.e. only one person in the train
	list_t w = wagons;

	// go to the start wagon
	for (i = 0; i < start_wagon; i++)
		w = w->next;

	// turn off the light in the first wagon
	// and move to the next one
	w->value = 0;
	w = w->next;
	offset_from_beginning++;
	count++;

	while (1) {
		// keep looking
		if (w->value == 1) {
			offset_from_beginning++;
			count++;
			w = w->next;
		}
		else {
			// turn on the light in the current wagon
			w->value = 1;

			// go back to wagon 1
			for (i = 0; i < offset_from_beginning; i++)
				w = w->prev;

			// if the light in the starting wagon is on,
			// then all wagons were traversed
			if (w->value == 1)
				return count;
			else
				// continue looking from where we left
				for (i = 0; i < offset_from_beginning; i++)
					w = w->next;
		}
	}

	// unlikely
	return -1;
}

void check(int count)
{
	if (count == len(states))
		printf("CORRECT\n");
	else
		printf("WRONG\n");
}

int main(int argc, char const *argv[])
{
	int i;

	list_t wagons = make_railway();

	//print(wagons);

	// consider each wagon as a start wagon
	for (i = 0; i < len(states); i++)
		check(count(wagons, i));


	// free memory
	for(i = 0; i < len(states); i++) {
		list_t aux = wagons;
		wagons = wagons->next;
		free(aux);
	}

	return 0;
}
