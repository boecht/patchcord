#include <aoo.h>

#include <cstdio>
#include <cstring>

int main(int argc, char *argv[]) {
    if (argc == 2 && std::strcmp(argv[1], "--version") == 0) {
        std::printf("patchcord %s\naoo %s\n", PATCHCORD_VERSION,
                    aoo_getVersionString());
        return 0;
    }
    std::fprintf(stderr, "usage: patchcord --version\n");
    return 2;
}
