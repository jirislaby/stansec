add_test(NAME nonExistantSource
	COMMAND stansec non_existant_source123.c
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set_property(TEST nonExistantSource
	PROPERTY PASS_REGULAR_EXPRESSION "Cannot open")

add_test(NAME nonExistantChecker
	COMMAND stansec -c NonExistantChecker lock_good.c
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set_property(TEST nonExistantChecker
	PROPERTY PASS_REGULAR_EXPRESSION "Could not create NonExistantChecker")

add_test(NAME automatonNoParam
	COMMAND stansec -c AutomatonChecker lock_good.c
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set_property(TEST automatonNoParam
	PROPERTY PASS_REGULAR_EXPRESSION "Could not create AutomatonChecker")

add_test(NAME automatonBadParam
	COMMAND stansec -c AutomatonChecker:non_existant_auto123.xml lock_good.c
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set_property(TEST automatonBadParam
	PROPERTY PASS_REGULAR_EXPRESSION "Cannot open .*non_existant_auto123.xml")

add_test(NAME lockBadLeavingTest
	COMMAND stansec -c AutomatonChecker:auto.xml lock_bad.c
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set_property(TEST lockBadLeavingTest
	PROPERTY PASS_REGULAR_EXPRESSION "leaving function in locked state")

add_test(NAME lockBadDoubleTest
	COMMAND stansec -c AutomatonChecker:auto.xml lock_bad.c
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set_property(TEST lockBadDoubleTest
	PROPERTY PASS_REGULAR_EXPRESSION "double lock")

add_test(NAME lockGoodTest
	COMMAND stansec -c AutomatonChecker:auto.xml lock_good.c
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set_property(TEST lockGoodTest
	PROPERTY FAIL_REGULAR_EXPRESSION "error \".*\" at:")

add_test(NAME reachBadTest
	COMMAND stansec -c ReachabilityChecker reach_bad.c
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set_property(TEST reachBadTest
	PROPERTY PASS_REGULAR_EXPRESSION "This node is unreachable .*line: 7")
