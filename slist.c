#include <glib.h>
#include "main.h"

void print_elem(gpointer item, gpointer prefix)
{
	g_message("%s %d", (char *)prefix, GPOINTER_TO_INT(item));
}

int main_slist()
{
	const int N = 10;
	GSList *list = NULL;

	for (int i = 0; i < N; i++) {
		list = g_slist_append(list, GINT_TO_POINTER(i));
	}
	g_slist_foreach(list, (GFunc)print_elem, "-->");
	g_slist_free(list);

	return 0;
}
