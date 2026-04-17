// Locate libraries
find_package(Qt6 6.5 REQUIRED COMPONENTS
    Quick
    Widgets)

// Link build target to libraries
target_link_libraries(${TARGET_NAME} PRIVATE
    Qt6::Quick
    Qt6::Widgets)

// Replace ${TARGET_NAME} with the name of your target executable