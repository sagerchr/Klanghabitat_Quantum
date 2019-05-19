#ifndef SCREEN1_VIEW_HPP
#define SCREEN1_VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void scrollListUpdateItem(imageContainer& item, int16_t itemIndex);
    virtual void scrollWheelUpdateItem(textContainer& item, int16_t itemIndex);
    virtual void scrollWheelUpdateCenterItem(textCenterContainer& item, int16_t itemIndex);

    virtual void scrollListSelected();
    virtual void scrollWheelSelected();


protected:

    // Callback which is executed when a item in the scroll list is selected.
    // The parameter itemSelected is the selected item.
    Callback<Screen1View, int16_t> scrollListItemSelectedCallback;
    void scrollListItemSelectedHandler(int16_t itemSelected);

    // Callback which is executed when a item in the scroll whell is selected to as selected style.
    // The parameter itemSelected is the selected item.
    Callback<Screen1View, int16_t> scrollWheelAnimateToCallback;
    void scrollWheelAnimateToHandler(int16_t itemSelected);

};

#endif // SCREEN1_VIEW_HPP
