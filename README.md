kstring
=======

In no particular order:


    A short report:
        Verbally describe the problem and your solution. 
        Don't copy declarations and definitions from the program - your code should be self-documenting. 
        Instead, report things that are not so self-evident from the program code. 
        These include explanations of solutions or decisions, the overall organization or dependencies, 
            and tricky problems or interesting experiences. 
        The report should clearly show that you recognized the relevant problems and found your solutions to them. 
        Report any remaining errors, shortcomings, or limitations of your implementation.

    Test drive:
         Write your own test driver to ensure the correct behaviour of the class (you may not use any existing unit testing tool).
         Remember that pre-condition checks are an essential part of well-defined library components. Also, use assertions (post-conditions) liberally. 
         These help to identify and locate problems near the place where they are born. 
         Don't depend on manually inspecting results or output, but create non-interactive self-contained tests 
         that create their own data and check the expected results. Remember that a "test failure" means a successful bug discovery.

        Especially:
            define the expected return values and programmatically check them with a suitable helper routine (defined in the test driver, e.g., checkSame (result, expected))
            a necessary (but not necessarily sufficient) requirement is that tests execute each part of the source; so, every function must be tested (at least) once
            check that exceptions are thrown on pre-condition violations and other errors (on purposely faulty calls/input values)
            catch these exceptions in the driver - and continue with tests
            test overloaded IO operations using std::stringstreams (since the test driver is not an interactive application)
            remember to free any allocated memory
            use leak detection facilities (your own/3rd party); e.g., simply sum allocations and releases
            remember to use the correct variant of delete/delete[]
            remember that end() does not point to the last element but beyond it
            catch any last escaping "stray" exceptions in the main (eventually there should not be such exceptions)
            replace ANSI C assert by your own custom "Assert" that throws exceptions, as Java assert does (since C assert aborts testing!)
            #defining NDEBUG should turn your own Assert off (to remove extra debugging code)
            at the end of a run, the driver reports the total number of failures - or success!
            make the test driver optionally print out each failure (but still continue with testing)
            consider adding a textual diagnostic to your assertion/check statements (to be printed out on a log file and/or a console)
            Finally, you must run the tests with debugging set off ("NDEBUG") - for the final "production" version of your software.

			