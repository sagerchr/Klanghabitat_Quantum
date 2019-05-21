#ifndef TEXTCONTAINER_HPP
#define TEXTCONTAINER_HPP

#include <gui_generated/containers/textContainerBase.hpp>

class textContainer : public textContainerBase
{
public:
    textContainer();
    virtual ~textContainer() {}

    void updateText(int16_t value);
protected:
};

#endif // TEXTCONTAINER_HPP
