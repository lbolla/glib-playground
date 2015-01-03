#include <glib.h>

void test_success()
{
	g_assert(TRUE);
}

void test_failure()
{
	g_assert(FALSE);
}

int main_testing(int argn, char *argv[])
{
	g_test_init(&argn, &argv, NULL);
	g_test_add_func("/asserts/success", test_success);
	g_test_add_func("/asserts/failure", test_failure);
	g_test_run();
	return 0;
}
