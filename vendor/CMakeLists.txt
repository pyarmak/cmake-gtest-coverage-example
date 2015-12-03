add_library(vendor simple_vendor.cpp simple_vendor.h vendor.h vendorio.h stream_vendorio.cpp stream_vendorio.h mock_vendorio.h)

# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
target_include_directories (vendor PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
