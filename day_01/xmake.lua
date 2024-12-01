add_rules("mode.debug", "mode.release")

set_warnings("all", "error")

target("day_01")
    -- Run dir is required to get all its files
    set_rundir("$(projectdir)/")

    set_kind("binary")
    add_files("src/*.c")
    add_headerfiles("../libs/*.h")
