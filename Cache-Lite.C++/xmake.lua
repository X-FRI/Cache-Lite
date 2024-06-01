add_rules("mode.debug", "mode.release")

add_requires("catch2 3.4.0")

target("cache_lite")
    set_kind("headeronly")
    add_files("src/*.h")

target("test")
  set_group("test")
  add_includedirs("src")
  add_files("test/*.cpp")
  add_packages("catch2 3.4.0")