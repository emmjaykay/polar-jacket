#ifndef _GET_CIV_HPP
#define _GET_CIV_HPP

#include "CivetServer.h"
#include <modeldb.hpp>

#include <boost/asio/io_service.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/bind/protect.hpp>

#include <iostream>

class get: public CivetHandler
{
public:
  bool handleGet(CivetServer *server, struct mg_connection *conn);

};

#endif
