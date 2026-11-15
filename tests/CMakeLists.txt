add_test(NAME patchcord_version COMMAND patchcord --version)
# Both lines must appear; the pattern also enforces their order.
set_tests_properties(patchcord_version PROPERTIES
    PASS_REGULAR_EXPRESSION "patchcord 0\\.1\\.0\naoo 2\\.0-test4\n")
