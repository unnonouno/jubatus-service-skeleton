// this program is automatically generated by jenerator. do not edit.
#include <jubatus/framework.hpp>
#include "kvs_server.hpp"
#include "kvs_serv.hpp"
using namespace jubatus;
using namespace jubatus::framework;
#define RETURN_OR_THROW(f) try { \
  return f; \
} catch (const jubatus::exception::jubatus_exception& e) { \
  LOG(WARNING) << e.diagnostic_information(true); \
  throw; \
} catch (const std::exception& e) { \
  LOG(ERROR) << e.what(); \
  throw; \
}
namespace jubatus { namespace server {
class kvs_impl_ : public kvs<kvs_impl_>
{
public:
  kvs_impl_(const server_argv& a):
    kvs<kvs_impl_>(a.timeout),
    p_(new server_helper<kvs_serv>(a, true))
  {}

  bool put(std::string name, std::string key, std::string value) //update cht(2)
  { JWLOCK__(p_); RETURN_OR_THROW(get_p()->put(key, value)); }

  std::string get(std::string name, std::string key) //analysis cht(2)
  { JRLOCK__(p_); RETURN_OR_THROW(get_p()->get(key)); }

  bool del(std::string name, std::string key) //update cht(2)
  { JWLOCK__(p_); RETURN_OR_THROW(get_p()->del(key)); }

  bool clear(std::string name) //update broadcast
  { JWLOCK__(p_); RETURN_OR_THROW(get_p()->clear()); }

  std::map<std::string,std::map<std::string,std::string > > get_status(std::string name) //analysis broadcast
  { JRLOCK__(p_); RETURN_OR_THROW(p_->get_status()); }

  bool save(std::string name, std::string id) //update broadcast
  { JWLOCK__(p_); RETURN_OR_THROW(get_p()->save(id)); }

  bool load(std::string name, std::string id) //update broadcast
  { JWLOCK__(p_); RETURN_OR_THROW(get_p()->load(id)); }
  int run(){ return p_->start(*this); };
  common::cshared_ptr<kvs_serv> get_p(){ return p_->server(); };
private:
  common::cshared_ptr<server_helper<kvs_serv> > p_;
};
}} // namespace jubatus::server
int main(int args, char** argv){
  return
    jubatus::framework::run_server<jubatus::server::kvs_impl_,
                                   jubatus::server::kvs_serv>
       (args, argv, "kvs");
}
