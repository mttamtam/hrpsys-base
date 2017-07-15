// -*- mode: c++; indent-tabs-mode: t; tab-width: 4; c-basic-offset: 4; -*-
#include <iostream>
#include "ContactExplorerService_impl.h"

ContactExplorerService_impl::ContactExplorerService_impl()
{
}

ContactExplorerService_impl::~ContactExplorerService_impl()
{
}

void ContactExplorerService_impl::echo(const char *msg)
{
	std::cout << "ContactExplorerService: " << msg << std::endl;
}

