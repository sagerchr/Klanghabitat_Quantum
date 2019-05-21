#include <gui/containers/textCenterContainer.hpp>

textCenterContainer::textCenterContainer()
{

}

void textCenterContainer::updateText(int16_t value)
{
    Unicode::snprintf(textBuffer, TEXT_SIZE, "%d", value);
    text.invalidate();
}
