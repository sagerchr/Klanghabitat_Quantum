#ifndef TEXTCENTERCONTAINER_HPP
#define TEXTCENTERCONTAINER_HPP

#include <gui_generated/containers/textCenterContainerBase.hpp>

class textCenterContainer : public textCenterContainerBase
{
public:
    textCenterContainer();
    virtual ~textCenterContainer() {}

    void updateText(int16_t value);
protected:
};

#endif // TEXTCENTERCONTAINER_HPP
