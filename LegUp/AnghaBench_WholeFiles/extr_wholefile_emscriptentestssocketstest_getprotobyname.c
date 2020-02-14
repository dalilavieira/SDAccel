#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct protoent {char const* p_name; int p_proto; char** p_aliases; } ;

/* Variables and functions */
 int EXIT_SUCCESS ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  endprotoent () ; 
 struct protoent* getprotobyname (char const*) ; 
 struct protoent* getprotobynumber (int) ; 
 struct protoent* getprotoent () ; 
 int /*<<< orphan*/  puts (char*) ; 
 int /*<<< orphan*/  setprotoent (int) ; 
 scalar_t__ strcmp (char const*,char const*) ; 

void checkEntryByValue(const char* name, int port, const char** aliasArray) {
    struct protoent* entry;
    char** aliases;

    // Perform a protocol look up by name
    entry = getprotobyname(name);
    assert(entry != NULL);

    // Check results
    assert(strcmp(name, entry->p_name) == 0);
    assert(port == entry->p_proto);

    aliases = entry->p_aliases;
    for (int i = 0; aliases[i] != NULL; i++) {
        assert(strcmp(aliases[i], aliasArray[i]) == 0);
    }

    // Perform a protocol look up by number
    entry = getprotobynumber(port);
    assert(entry != NULL);

    // Check results
    assert(strcmp(name, entry->p_name) == 0);
    assert(port == entry->p_proto);

    aliases = entry->p_aliases;
    for (int i = 0; aliases[i] != NULL; i++) {
        assert(strcmp(aliases[i], aliasArray[i]) == 0);
    }
}

void checkEntryDatabase() {
    struct protoent* entry;

    // Don't call setprotoent() initially as getprotoent() should open the "database" if necessary.
    entry = getprotoent();
    assert(entry != NULL);
    assert(strcmp("tcp", entry->p_name) == 0);

    entry = getprotoent();
    assert(entry != NULL);
    assert(strcmp("udp", entry->p_name) == 0);

    // Check that setprotoent() correctly sets the next entry to the first entry
    setprotoent(1);

    entry = getprotoent();
    assert(entry != NULL);
    assert(strcmp("tcp", entry->p_name) == 0);

    entry = getprotoent();
    assert(entry != NULL);
    assert(strcmp("udp", entry->p_name) == 0);

    // If we do a getprotoent() that goes past the end of the 'database' check that it returns NULL.
    entry = getprotoent();
    assert(entry == NULL);
}

int main() {
    // First check getprotobyname() and getprotobynumber()
    const char* aliases[] = {"TCP"};
    checkEntryByValue("tcp", 6, aliases);

    aliases[0] = "UDP";
    checkEntryByValue("udp", 17, aliases);

    // Check that the doomsday protocol hasn't been implemented :-) ......
    assert(getprotobyname("doomsday") == NULL);

    // Now check setprotoent() and getprotoent()
    checkEntryDatabase();

    endprotoent();

    puts("success");

    return EXIT_SUCCESS;
}

