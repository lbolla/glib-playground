#include <glib.h>

void print_elem(gpointer item, gpointer prefix)
{
	g_message("%s %ld", (char *)prefix, (long)item);
}

int main_slist(int argn, char *argv[])
{
	const int N = 10;
	GSList *list = NULL;

	for (long i = 0; i < N; i++) {
		list = g_slist_append(list, (gpointer)i);
	}
	g_slist_foreach(list, (GFunc)print_elem, "-->");
	g_slist_free(list);

	return 0;
}
