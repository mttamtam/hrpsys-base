set(comp_sources ContactExplorer.cpp ContactExplorerService_impl.cpp)
set(libs hrpsysBaseStub)
add_library(ContactExplorer SHARED ${comp_sources})
target_link_libraries(ContactExplorer ${libs})
set_target_properties(ContactExplorer PROPERTIES PREFIX "")

add_executable(ContactExplorerComp ContactExplorerComp.cpp ${comp_sources})
target_link_libraries(ContactExplorerComp ${libs})

set(target ContactExplorer ContactExplorerComp)

install(TARGETS ${target}
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
)
