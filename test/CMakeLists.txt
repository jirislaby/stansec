add_test(NAME lockBadLeavingTest
	COMMAND stansec lock_bad.c
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set_property(TEST lockBadLeavingTest
	PROPERTY PASS_REGULAR_EXPRESSION "leaving function in locked state")

add_test(NAME lockBadDoubleTest
	COMMAND stansec lock_bad.c
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set_property(TEST lockBadDoubleTest
	PROPERTY PASS_REGULAR_EXPRESSION "double lock")

add_test(NAME lockGoodTest
	COMMAND stansec lock_good.c
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set_property(TEST lockGoodTest
	PROPERTY FAIL_REGULAR_EXPRESSION "error \".*\" at:")

add_test(NAME reachBadTest
	COMMAND stansec reach_bad.c
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set_property(TEST reachBadTest
	PROPERTY PASS_REGULAR_EXPRESSION "This node is unreachable .*line: 7")
