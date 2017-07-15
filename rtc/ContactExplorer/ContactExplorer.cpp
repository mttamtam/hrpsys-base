// -*- C++ -*-
/*!
 * @file  ContactExplorer.cpp
 * @brief contactexplorer component
 * $Date$
 *
 * $Id$
 */

#include "hrpsys/util/VectorConvert.h"
#include "ContactExplorer.h"

// Module specification
// <rtc-template block="module_spec">
static const char* contactexplorer_spec[] =
  {
    "implementation_id", "ContactExplorer",
    "type_name",         "ContactExplorer",
    "description",       "contact explorer component",
    "version",           HRPSYS_PACKAGE_VERSION,
    "vendor",            "AIST",
    "category",          "example",
    "activity_type",     "DataFlowComponent",
    "max_instance",      "10",
    "language",          "C++",
    "lang_type",         "compile",
    // Configuration variables
    "conf.default.debugLevel", "0",
    ""
  };
// </rtc-template>

ContactExplorer::ContactExplorer(RTC::Manager* manager)
  : RTC::DataFlowComponentBase(manager),
    // <rtc-template block="initializer">
    m_dataIn("dataIn", m_data),
    m_dataOut("dataOut", m_data),
    m_ContactExplorerServicePort("ContactExplorerService"),
    // </rtc-template>
	dummy(0)
{
  std::cout << "ContactExplorer::ContactExplorer()" << std::endl;
  m_data.data = 0;
}

ContactExplorer::~ContactExplorer()
{
  std::cout << "ContactExplorer::~ContactExplorer()" << std::endl;
}



RTC::ReturnCode_t ContactExplorer::onInitialize()
{
  std::cout << m_profile.instance_name << ": onInitialize()" << std::endl;
  // <rtc-template block="bind_config">
  // Bind variables and configuration variable
  bindParameter("string", confstring, "testtest");
  bindParameter("intvec", confintvec, "4,5,6,7");
  bindParameter("double", confdouble, "4.567");
  
  // </rtc-template>

  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("dataIn", m_dataIn);

  // Set OutPort buffer
  addOutPort("dataOut", m_dataOut);
  
  // Set service provider to Ports
  m_ContactExplorerServicePort.registerProvider("service0", "ContactExplorerService", m_ContactExplorerService);
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  addPort(m_ContactExplorerServicePort);
  
  // </rtc-template>

  RTC::Properties& prop = getProperties();
  std::cout << "prop[\"testconf\"] = " << prop["testconf"] << std::endl;

  return RTC::RTC_OK;
}



/*
RTC::ReturnCode_t ContactExplorer::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ContactExplorer::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ContactExplorer::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

RTC::ReturnCode_t ContactExplorer::onActivated(RTC::UniqueId ec_id)
{
  std::cout << m_profile.instance_name<< ": onActivated(" << ec_id << ")" << std::endl;
  return RTC::RTC_OK;
}

RTC::ReturnCode_t ContactExplorer::onDeactivated(RTC::UniqueId ec_id)
{
  std::cout << m_profile.instance_name<< ": onDeactivated(" << ec_id << ")" << std::endl;
  return RTC::RTC_OK;
}

RTC::ReturnCode_t ContactExplorer::onExecute(RTC::UniqueId ec_id)
{
  std::cout << m_profile.instance_name<< ": onExecute(" << ec_id << "), data = " << m_data.data << std::endl;
  std::cout << "confstring = " << confstring << std::endl;
  std::cout << "confintvec = ";
  for (unsigned int i=0; i<confintvec.size(); i++){
      std::cout << confintvec[i] << " ";
  }
  std::cout << std::endl;
  std::cout << "confdouble = " << confdouble << std::endl;

  while (m_dataIn.isNew()){
      m_dataIn.read();
      std::cout << m_profile.instance_name << ": read(), data = " << m_data.data << std::endl;
  }
  m_data.data += 1;

  m_dataOut.write();
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ContactExplorer::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ContactExplorer::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ContactExplorer::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ContactExplorer::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ContactExplorer::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{

  void ContactExplorerInit(RTC::Manager* manager)
  {
    RTC::Properties profile(contactexplorer_spec);
    manager->registerFactory(profile,
                             RTC::Create<ContactExplorer>,
                             RTC::Delete<ContactExplorer>);
  }

};


