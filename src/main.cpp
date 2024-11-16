/*
 * Password Manager - Witty Application
 *
 * Main driver
 * mmerkle, 11/15/2024
*/

#include <memory>

#include <Wt/WApplication.h>

#include "passMangApp.h"

int
main(int argc, char** argv)
{
	return Wt::WRun(argc, argv, [](const Wt::WEnvironment& env) {
		return std::make_unique<passMangApp>(env);
	});
}
