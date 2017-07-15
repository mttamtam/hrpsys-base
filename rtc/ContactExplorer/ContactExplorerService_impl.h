// -*- mode: c++; indent-tabs-mode: t; tab-width: 4; c-basic-offset: 4; -*-
#ifndef __CONTACTEXPLORER_SERVICE_H__
#define __CONTACTEXPLORER_SERVICE_H__

#include "hrpsys/idl/ContactExplorerService.hh"

class ContactExplorerService_impl
	: public virtual POA_OpenHRP::ContactExplorerService,
	  public virtual PortableServer::RefCountServantBase
{
public:
	/**
	   \brief constructor
	*/
	ContactExplorerService_impl();

	/**
	   \brief destructor
	*/
	virtual ~ContactExplorerService_impl();

	void echo(const char *msg);
private:
};

#endif
