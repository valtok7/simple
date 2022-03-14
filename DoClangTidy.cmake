cmake_minimum_required(VERSION 3.6)

find_program(CLANG_TIDY_EXE NAMES "clang-tidy" DOC "Path to clang-tidy executable" )
if(NOT CLANG_TIDY_EXE) 
  message(STATUS "clang-tidy not found.") 
else() 
  message(STATUS "clang-tidy found: ${CLANG_TIDY_EXE}") 
#  set(DO_CLANG_TIDY "${CLANG_TIDY_EXE}" "-checks=*,-clang-analyzer-alpha.*") 
  set(DO_CLANG_TIDY "${CLANG_TIDY_EXE}" 
    "-checks=*,bugprone-macro-parentheses,bugprone-redundant-branch-condition,cppcoreguidelines-init-variables,cppcoreguidelines-pro-type-member-init,misc-redundant-expression,cppcoreguidelines-pro-type-cstyle-cast,cppcoreguidelines-virtual-class-destructor,llvm-include-order,misc-definitions-in-headers,modernize-redundant-void-arg,modernize-use-bool-literals,portability-restrict-system-includes,readability-convert-member-functions-to-static,readability-make-member-function-const, readability-non-const-parameter,readability-qualified-auto,readability-redundant-control-flow,readability-redundant-member-init,readability-const-return-type,misc-static-assert,modernize-make-shared,modernize-make-unique,modernize-use-auto,modernize-use-default-member-init,modernize-use-emplace,modernize-use-equals-delete,modernize-use-nullptr,modernize-use-override,modernize-use-using")
endif()