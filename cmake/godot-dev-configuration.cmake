# =======================================================================
# Godot Engine submodule update/init
# =======================================================================

# confirm we found the godot engine source files.
# if the sources list is empty, the submodule probably
# hasn't been initialized or updated yet.

# =======================================================================
# Godot-cpp bindings submodule update/init
# =======================================================================

# confirm we found the godot engine source files.
# if the sources list is empty, the submodule probably
# hasn't been initialized or updated yet.
if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/godot-cpp/src")
    message(NOTICE "godot-cpp bingings source not found")
    message(NOTICE "initializing/updating the godot-cpp submodule...")

    # update the c++ bingings submodule to populate it with
    # the necessary source for the gdextension library
    execute_process(
        COMMAND git submodule update --init extern/godot-cpp
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMAND_ERROR_IS_FATAL ANY
    )
endif()

# =======================================================================
# Godot editor/engine debug build
# =======================================================================

string(TOLOWER "${CMAKE_SYSTEM_NAME}" host_os)
set(cpu_arch "x86_64")

# define variable to be used in the engine build when specifying platform.
set(host_os_engine "${host_os}")
if (APPLE)
    if ("${CMAKE_SYSTEM_PROCESSOR}" STREQUAL "arm64")
            set(cpu_arch "arm64")
    endif()
    # ${CMAKE_SYSTEM_NAME} returns Darwin, but the scons platform name will be macos
    set(host_os_engine "macos")
elseif(UNIX)
    # the scons build expects linuxbsd to be passed in as the platform
    # when building on linux, so just append bsd to CMAKE_SYSTEM_NAME
    set(host_os_engine "${host_os}bsd")
endif()

# if the engine/editor executable isn't found in the
# engine's submodule bin folder, invoke the scons build.

# =======================================================================
# Godot C++ bindings library setup/configuration
# =======================================================================

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/godot-cpp)

# =======================================================================
# Godot engine library setup/configuration.
# Not necessary, just provides better support in multiple IDEs
# for engine source code browsing, intellisense, and debugging
# =======================================================================

# populate source file list for the godot engine submodule

# add the engine sources as a library so intellisense works in VS and VSCode
# (and any other IDEs that support CMake in a way where the information from
# the CMake build is fed into the IDE for additional context about the code
# when browsing/debugging). even though the engine is being added as a library here,
# the EXCLUDE_FROM_ALL option will prevent it from compiling. This is done
# purely for IDE integration so it's able to properly navigate the engine
# source code using features like "go do definition", or typical tooltips

# this is just a handful of additional include directories used by the engine.
# this isn't a complete list, I just add them as needed whenever I venture into
# code where the IDE can't find certain header files during engine source browsing.

# define a bunch of the same symbol definitions
# used when by the scons engine build. These build
# flags can differen based on the engine's build for
# you system. Update as needed for your setup.

