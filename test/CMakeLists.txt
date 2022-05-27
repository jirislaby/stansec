add_test(NAME nonExistantSource
	COMMAND stansec non_existant_source123.c
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set_tests_properties(nonExistantSource PROPERTIES
	PASS_REGULAR_EXPRESSION "Cannot open"
        ENVIRONMENT "QT_FORCE_STDERR_LOGGING=1")

add_test(NAME nonExistantChecker
	COMMAND stansec -c NonExistantChecker lock_good.c
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set_tests_properties(nonExistantChecker PROPERTIES
	PASS_REGULAR_EXPRESSION "Could not create NonExistantChecker"
        ENVIRONMENT "QT_FORCE_STDERR_LOGGING=1")

add_test(NAME automatonNoParam
	COMMAND stansec -c AutomatonChecker lock_good.c
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set_tests_properties(automatonNoParam PROPERTIES
	PASS_REGULAR_EXPRESSION "Could not create AutomatonChecker"
        ENVIRONMENT "QT_FORCE_STDERR_LOGGING=1")

add_test(NAME automatonBadParam
	COMMAND stansec -c AutomatonChecker:non_existant_auto123.xml lock_good.c
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set_tests_properties(automatonBadParam PROPERTIES
	PASS_REGULAR_EXPRESSION "Cannot open .*non_existant_auto123.xml"
        ENVIRONMENT "QT_FORCE_STDERR_LOGGING=1")

add_test(NAME lockBadLeavingTest
	COMMAND stansec -c AutomatonChecker:auto.xml lock_bad.c
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set_tests_properties(lockBadLeavingTest PROPERTIES
	PASS_REGULAR_EXPRESSION "leaving function in locked state"
        ENVIRONMENT "QT_FORCE_STDERR_LOGGING=1")

add_test(NAME lockBadDoubleTest
	COMMAND stansec -c AutomatonChecker:auto.xml lock_bad.c
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set_tests_properties(lockBadDoubleTest PROPERTIES
	PASS_REGULAR_EXPRESSION "double lock"
        ENVIRONMENT "QT_FORCE_STDERR_LOGGING=1")

add_test(NAME lockMemberTest
	COMMAND stansec -c AutomatonChecker:auto.xml lock_member.c
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set_tests_properties(lockMemberTest PROPERTIES
	FAIL_REGULAR_EXPRESSION "error \".*\" at:"
        ENVIRONMENT "QT_FORCE_STDERR_LOGGING=1")

add_test(NAME lockLocalTest
	COMMAND stansec -c AutomatonChecker:auto.xml lock_local.c
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set_tests_properties(lockLocalTest PROPERTIES
	FAIL_REGULAR_EXPRESSION "error \".*\" at:"
        ENVIRONMENT "QT_FORCE_STDERR_LOGGING=1")

add_test(NAME lockGlobalGoodTest
	COMMAND stansec -c AutomatonChecker:auto.xml lock_global_good.c
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set_tests_properties(lockGlobalGoodTest PROPERTIES
	FAIL_REGULAR_EXPRESSION "error \".*\" at:"
        ENVIRONMENT "QT_FORCE_STDERR_LOGGING=1")

add_test(NAME lockGoodTest
	COMMAND stansec -c AutomatonChecker:auto.xml lock_good.c
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set_tests_properties(lockGoodTest PROPERTIES
	FAIL_REGULAR_EXPRESSION "error \".*\" at:"
        ENVIRONMENT "QT_FORCE_STDERR_LOGGING=1")

add_test(NAME reachBadTest
	COMMAND stansec -c ReachabilityChecker reach_bad.c
	WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set_tests_properties(reachBadTest PROPERTIES
	PASS_REGULAR_EXPRESSION "This node is unreachable .*line: 7"
        ENVIRONMENT "QT_FORCE_STDERR_LOGGING=1")
