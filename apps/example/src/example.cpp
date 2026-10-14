import std;

import syslog;

int main() {
    syslog::fatal("Fatal");
    syslog::error("Error");
    syslog::warning("Warning");
    syslog::info("Info");
    syslog::note("Note");
    syslog::debug("Debug");
    return 0;
}
