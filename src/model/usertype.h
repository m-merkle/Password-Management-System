#ifndef USER_H
#define USER_H

#
#
namespace petShop {

enum class Role {
Admin,
Regular,
ViewOnly
};

class Usertype {
  public:
    userType() = delete;
    userType(User t);

    Role getType() const;
    std::string getText() const;

  private:
    Role type;
    std::string text;
};

}
#endif
