#include <Pet.hpp>
#include <definitions.h>

#ifndef HANDLER_HPP
#define HANDLER_HPP

class Handler {

protected:
  Handler *_next = nullptr;

public:
  Handler() {}
  Handler(Handler *next) { setNextHandler(next); }
  virtual void setNextHandler(Handler *next) { _next = next; }
  virtual void handleState(Pet *pet){};
  /**
   * @brief Releases this handler and next handlers. Return true if the next
   * handler was the last handler.
   *
   * @return true Next handler is the last handler.
   * @return false
   */
  virtual bool release() {
    if (_next == nullptr)
      return true;
    else {
      if (_next->release())
        delete _next;
    }
  }
  virtual ~Handler() = default;
};

#endif // HANDLER_HPP