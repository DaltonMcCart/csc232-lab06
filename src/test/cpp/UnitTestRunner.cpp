/**
 * CSC232 Data Structures with C++
 * Missouri State University, Spring 2019.
 *
 * DO NOT MODIFY THE CONTENTS OF THIS FILE!
 * Doing so will result in a 0 for this assignment (and it could break the tests)!
 *
 * @file   UnitTestRunner.cpp
 * @author Jim Daehn <jdaehn@missouristate.edu>
 * @brief  Test Runner for running all Lab unit tests.
 * @see    http://sourceforge.net/projects/cppunit/files
 *
 * @copyright Jim Daehn, 2017. All rights reserved.
 */

#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>

#include <cppunit/TestFailure.h>

/**
 * @brief Main test driver for CPPUNIT test suite.
 * @remark DO NOT MODIFY THE SPECIFICATION OR IMPLEMENTATION OF THIS CLASS! ANY
 *         MODIFICATION TO THIS CLASS WILL RESULT IN A GRADE OF 0 FOR THIS
 *         ASSIGNMENT!
 */
class ProgressListener : public CPPUNIT_NS::TestListener {
public:

    ProgressListener()
            : m_lastTestFailed(false) {
    }

    // Prevents the use of the copy constructor.
    ProgressListener(const ProgressListener &copy) = delete;

    // Prevents the use of the copy operator.
    void operator=(const ProgressListener &copy) = delete;

    ~ProgressListener() override = default;

    void startTest(CPPUNIT_NS::Test *test) override {
        CPPUNIT_NS::stdCOut() << test->getName();
        CPPUNIT_NS::stdCOut() << "\n";
        CPPUNIT_NS::stdCOut().flush();

        m_lastTestFailed = false;
    }

    void addFailure(const CPPUNIT_NS::TestFailure &failure) override {
        CPPUNIT_NS::stdCOut() << " : " << (failure.isError() ? "error" : "assertion");
        m_lastTestFailed = true;
    }

    void endTest(CPPUNIT_NS::Test *test) override {
        if (!m_lastTestFailed)
            CPPUNIT_NS::stdCOut() << " : OK";
        CPPUNIT_NS::stdCOut() << "\n";
    }

private:
    bool m_lastTestFailed;
};

int main() {
    // Create the event manager and test controller
    CPPUNIT_NS::TestResult controller;

    // Add a listener that collects test result
    CPPUNIT_NS::TestResultCollector result;
    controller.addListener(&result);

    // Add a listener that print dots as test run.
    ProgressListener progress;
    controller.addListener(&progress);

    // Add the top suite to the test runner
    CPPUNIT_NS::TestRunner runner;
    runner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
    runner.run(controller);

    // Print test in a compiler compatible format.
    CPPUNIT_NS::CompilerOutputter outputter(&result, CPPUNIT_NS::stdCOut());
    outputter.write();

    return result.wasSuccessful() ? 0 : 1;
}
