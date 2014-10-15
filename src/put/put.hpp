#ifndef _PUT_CIV_HPP
#define _PUT_CIV_HPP

#include "CivetServer.h"
#include <modeldb.hpp>

#include <boost/asio/io_service.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/bind/protect.hpp>

#include <iostream>

class put: public CivetHandler
{
public:
  bool handleGet(CivetServer *server, struct mg_connection *conn);
  bool handlePut(CivetServer *server, struct mg_connection *conn);
};

#endif
