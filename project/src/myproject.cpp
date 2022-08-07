#include "spdlog/spdlog.h"
#include <boost/asio.hpp>
#include <openssl/opensslv.h>

#include "myprojectconfig.hpp"
#include "myproject/myproject.hpp"

void myproject::MyProject::version()
{
  spdlog::info("libMyProject v{}.{}.{} uses the following libraries:",
               MYPROJECT_VERSION_MAJOR, MYPROJECT_VERSION_MINOR, MYPROJECT_VERSION_PATCH);
  spdlog::info("spdlog {}.{}.{} [MIT License, header only] {}",
               SPDLOG_VER_MAJOR, SPDLOG_VER_MINOR, SPDLOG_VER_PATCH,
               "https://github.com/gabime/spdlog");
  spdlog::info("Boost (v{}.{}.{}) Asio v{}.{}.{}", BOOST_VERSION / 100000, BOOST_VERSION / 100 % 1000, BOOST_VERSION % 100, BOOST_ASIO_VERSION / 100000, BOOST_ASIO_VERSION / 100 % 1000, BOOST_ASIO_VERSION % 100); // NOLINT
  spdlog::info(OPENSSL_VERSION_TEXT);
}
