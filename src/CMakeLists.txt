file(GLOB_RECURSE termulator_sources "./*.cpp")

add_executable(termulator ${termulator_sources})

# include_directories("/usr/include")
include_directories("/usr/include")

target_link_libraries(termulator
	"ncurses"
)
