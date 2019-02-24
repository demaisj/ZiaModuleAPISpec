add_library(log MODULE
    factory.cpp
)
set_target_properties(log PROPERTIES PREFIX "zia-")
target_link_libraries(log
    ${CONAN_LIBS_BOOST}
    ZiaModuleAPISpec
)
