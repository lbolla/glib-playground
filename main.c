#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include "main.h"

typedef int (main_t)(void);

void usage(void)
{
	fprintf(stderr, "Usage:\n\t./main [what]\n");
}

int main(int argn, char *argv[])
{
	int retval;
	GHashTable *main_map = g_hash_table_new(g_str_hash, g_str_equal);
	g_hash_table_insert(main_map, "slist", (gpointer)main_slist);
	g_hash_table_insert(main_map, "list", (gpointer)main_list);
	g_hash_table_insert(main_map, "loop", (gpointer)main_main_loop);

	if (argn < 2) {
		g_warning("No main given");
		usage();
		retval = EXIT_FAILURE;
		goto cleanup;
	}

	const char *what = g_strstrip(argv[1]);
	main_t *main_p = g_hash_table_lookup(main_map, what);
	if (main_p == NULL) {
		g_warning("No main found for \"%s\".", what);
		usage();
		retval = EXIT_FAILURE;
		goto cleanup;
	}

	retval = (*main_p)();

cleanup:
	g_hash_table_unref(main_map);
	return retval;
}
