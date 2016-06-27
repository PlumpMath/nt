cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(asm VERSION 0.1.0 LANGUAGES CXX)

# Configurations
set(CMAKE_CONFIGURATION_TYPES MinSizeRel)

# Compiler
enable_language(ASM_MASM)
if(NOT CMAKE_ASM_MASM_COMPILER_LOADED)
  message(FATAL_ERROR "Could not load the MASM compiler.")
endif()

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler Options
foreach(flag
    CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_MINSIZEREL)
  if(${flag} MATCHES "/MD")
    string(REPLACE "/MD" "/MT" ${flag} "${${flag}}")
  endif()
  if(${flag} MATCHES "/EHsc")
    string(REPLACE "/EHsc" "" ${flag} "${${flag}}")
  endif()
endforeach()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /O1 /Ob1 /Oi /Os /Oy /GS- /GR- /utf-8")

# Definitions
add_definitions(-D_UNICODE -DUNICODDE -DWIN32_LEAN_AND_MEAN -DNOMINMAX)
add_definitions(-D_CRT_SECURE_NO_DEPRECATE -D_CRT_NONSTDC_NO_DEPRECATE -D_ATL_SECURE_NO_DEPRECATE)
add_definitions(-D_CRT_SECURE_NO_WARNINGS -D_SCL_SECURE_NO_WARNINGS)
add_definitions(-DWINVER=0x0A00 -D_WIN32_WINNT=0x0A00)

# Linker Options
set(CMAKE_EXE_LINKER_FLAGS "/entry:main ${CMAKE_EXE_LINKER_FLAGS} /manifestuac:NO /nodefaultlib")
set(CMAKE_CXX_STANDARD_LIBRARIES "")

# Functions
function(assign_source_group)
  foreach(source IN ITEMS ${ARGN})
    if(IS_ABSOLUTE ${source})
      file(RELATIVE_PATH source "${CMAKE_CURRENT_SOURCE_DIR}" "${source}")
    endif()
    get_filename_component(source_path "${source}" PATH)
    if(MSVC)
      string(REPLACE "/" "\\" source_path "${source_path}")
    endif()
    source_group("${source_path}" FILES "${source}")
  endforeach()
endfunction(assign_source_group)

# Resources
file(GLOB_RECURSE res res/*)
assign_source_group(${res})

# Headers
file(GLOB_RECURSE headers src/*.h)
assign_source_group(${headers})

# Sources
file(GLOB_RECURSE sources src/*.asm src/*.cc)
assign_source_group(${sources})

# Executable
add_executable(${PROJECT_NAME} WIN32 ${res} ${headers} ${sources})
target_link_libraries(${PROJECT_NAME} LINK_INTERFACE_LIBRARIES "")
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME $<LOWER_CASE:${PROJECT_NAME}>)

# Include Directories
target_include_directories(${PROJECT_NAME}
  PRIVATE ${CMAKE_CURRENT_BINARY_DIR} src res)

# Install Target
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
