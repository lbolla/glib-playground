#include <glib.h>

gboolean f(GMainLoop *main_loop)
{
	static int n = 3;
	if (n-- == 0) {
		g_main_loop_quit(main_loop);
		return FALSE;
	}
	gint64 t = g_get_real_time();
	g_message("#%d f called %ld", n, t);
	return TRUE;
}

int main_main_loop(int argn, char *argv[])
{
	g_message("Create loop");
	GMainLoop *main_loop = g_main_loop_new(NULL, FALSE);

	guint ev_id = g_timeout_add_seconds(3, (GSourceFunc)f, main_loop);
	g_message("Created ev %d", ev_id);

	g_message("Run");
	g_main_loop_run(main_loop);

	g_message("Clear");
	g_main_loop_unref(main_loop);

	g_message("Done");
	return 0;
}
