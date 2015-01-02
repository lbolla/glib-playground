#include <glib.h>

typedef struct {
	char *name;
	int age;
} Person;

Person *person_new(char *name, int age) {
	Person *p = g_new(Person, 1);
	p->name = name;
	p->age = age;
	return p;
}

void person_free(Person *p) {
	g_free(p);
}

int main_list(void)
{
	const int N = 1;
	GList *list = NULL;

	for (int i = 0; i < N; i++) {
	    list = g_list_append(list, person_new("Lorenzo", i));
	}

	Person *p = (Person*)(g_list_first(list)->data);
	g_message("%s", p->name);

	g_list_free_full(list, (GDestroyNotify)person_free);

	return 0;
}
