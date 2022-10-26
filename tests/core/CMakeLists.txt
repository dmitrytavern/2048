set(CoreTests "${APP_PROJECT_NAME}_CoreTests")

add_executable(${CoreTests}
	"GameMatrixTest.cpp"
	"${PROJECT_SOURCE_DIR}/src/core/GameMatrix.cpp"
)

target_link_libraries(${CoreTests} PRIVATE Catch2::Catch2WithMain)
catch_discover_tests(${CoreTests})
