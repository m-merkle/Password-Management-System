# Model test code

* Unit tests - Focused on individual components of the code, such as classes or functions.
 
* Regression tests - Ensure that changes to the code do not introduce new bugs or regressions.

* Integration tests - Test how different components work together as a system.


*Instructions for Testing:

1. To create test: 
	-Follow the structure of existing tests in the repository.
	-Adjust the test code to fit the functionality of the file you are testing.

2. Alter the Makefile: 
	-Update the file names and dependencies in the Makefile to reflect the files you are testing.
	-Verify that any required header files or dependencies are included.

3. Running Test:
    	-make to compile tests files  
    	-run the test by ./utest
    	-make clean afterwards

*Unit Tests in this folder:
        -CredentialTest
        -UserClass
        -UserTypeClass

