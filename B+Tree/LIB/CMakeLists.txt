


# B+Tree SOURCE
file(GLOB SOURCE "src/*.c")

# B+Tree LIB
add_library(BPlus_Tree STATIC ${SOURCE})
target_include_directories(BPlus_Tree PUBLIC include)