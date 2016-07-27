#ifndef SERIALEXCEPTION_H
#define SERIALEXCEPTION_H
#include <stdexcept>



class MySerialException: public std::exception
{
public:
    explicit MySerialException(const char* message):
      msg_(message)
      {
      }

    explicit MySerialException(const std::string& message):
      msg_(message + std::to_string(errno))
      {}

    explicit MySerialException(const char* message):
      msg_(message)
      {
      }

    explicit MySerialException(const std::string& message):
      msg_(message + std::to_string(errno))
      {}

    virtual ~MySerialException() throw (){}

    virtual const char* what() const throw (){
       return msg_.c_str();
    }

protected:
    /** Error message.
     */
    std::string msg_;
};
#endif // SERIALEXCEPTION_H
