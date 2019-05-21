#include <gui/screen1_screen/Screen1View.hpp>
#include "BitmapDatabase.hpp"
#include "texts/TextKeysAndLanguages.hpp"

Screen1View::Screen1View() :
    scrollListItemSelectedCallback(this, &Screen1View::scrollListItemSelectedHandler),
    scrollWheelAnimateToCallback(this, &Screen1View::scrollWheelAnimateToHandler)
{
    // Support of larger displays for this example
    // is handled by showing a black box in the
    // unused part of the display.
    if (HAL::DISPLAY_WIDTH > background.getWidth() ||
            HAL::DISPLAY_HEIGHT > background.getHeight())
    {
        boxBackground.setVisible(true);
    }
}

void Screen1View::setupScreen()
{
    // The item selected callbacks are registerd with scroll wheel and list
    scrollList.setItemSelectedCallback(scrollListItemSelectedCallback);
    scrollWheel.setAnimateToCallback(scrollWheelAnimateToCallback);

    // The scroll wheel and list is updated to show the selected icons and numbers.
    for (int i = 0; i < scrollListListItems.getNumberOfDrawables(); i++)
    {
        scrollList.itemChanged(i);
    }
    scrollWheel.animateToItem(15);
}


void Screen1View::tearDownScreen()
{

}

// The scrollListUpdateItem is called by the base view each time an element in the scroll list is updated.
// By having a reference to the instance, which the switch updates the image based on the index the item has.
void Screen1View::scrollListUpdateItem(imageContainer& item, int16_t itemIndex)
{
    switch (itemIndex)
    {
    case 0:
        item.updateImage(Bitmap(BITMAP_ALERT_ID));
        break;
    case 1:
        item.updateImage(Bitmap(BITMAP_CALENDAR_ID));
        break;
    case 2:
        item.updateImage(Bitmap(BITMAP_DOCUMENT_ID));
        break;
    case 3:
        item.updateImage(Bitmap(BITMAP_EMAIL_ID));
        break;
    case 4:
        item.updateImage(Bitmap(BITMAP_FOLDER_ID));
        break;
    case 5:
        item.updateImage(Bitmap(BITMAP_HOME_ID));
        break;
    case 6:
        item.updateImage(Bitmap(BITMAP_INBOX_ID));
        break;
    case 7:
        item.updateImage(Bitmap(BITMAP_MAP_ID));
        break;
    case 8:
        item.updateImage(Bitmap(BITMAP_MOVIE_ID));
        break;
    case 9:
        item.updateImage(Bitmap(BITMAP_NEWS_ID));
        break;
    case 10:
        item.updateImage(Bitmap(BITMAP_SOUND_ID));
        break;
    case 11:
        item.updateImage(Bitmap(BITMAP_TOOLS_ID));
        break;
    case 12:
        item.updateImage(Bitmap(BITMAP_TRASH_ID));
        break;
    case 13:
        item.updateImage(Bitmap(BITMAP_USER_ID));
        break;
    }
}

// Similar to scrollListUpdateItem the two functions scrollWheelUpdateItem and scrollWheelUpdateCenterItem,
// updates the text in the scroll wheel based on the item's index
void Screen1View::scrollWheelUpdateItem(textContainer& item, int16_t itemIndex)
{
    item.updateText(itemIndex);
}
void Screen1View::scrollWheelUpdateCenterItem(textCenterContainer& item, int16_t itemIndex)
{
    item.updateText(itemIndex);
}

// The callback updates the selectedIcon bast on the itemSelected parameter
void Screen1View::scrollListItemSelectedHandler(int16_t itemSelected)
{
    selectedIcon.invalidate();

    switch (itemSelected)
    {
    case 0:
        selectedIcon.setBitmap(Bitmap(BITMAP_ALERT_ID));
        break;
    case 1:
        selectedIcon.setBitmap(Bitmap(BITMAP_CALENDAR_ID));
        break;
    case 2:
        selectedIcon.setBitmap(Bitmap(BITMAP_DOCUMENT_ID));
        break;
    case 3:
        selectedIcon.setBitmap(Bitmap(BITMAP_EMAIL_ID));
        break;
    case 4:
        selectedIcon.setBitmap(Bitmap(BITMAP_FOLDER_ID));
        break;
    case 5:
        selectedIcon.setBitmap(Bitmap(BITMAP_HOME_ID));
        break;
    case 6:
        selectedIcon.setBitmap(Bitmap(BITMAP_INBOX_ID));
        break;
    case 7:
        selectedIcon.setBitmap(Bitmap(BITMAP_MAP_ID));
        break;
    case 8:
        selectedIcon.setBitmap(Bitmap(BITMAP_MOVIE_ID));
        break;
    case 9:
        selectedIcon.setBitmap(Bitmap(BITMAP_NEWS_ID));
        break;
    case 10:
        selectedIcon.setBitmap(Bitmap(BITMAP_SOUND_ID));
        break;
    case 11:
        selectedIcon.setBitmap(Bitmap(BITMAP_TOOLS_ID));
        break;
    case 12:
        selectedIcon.setBitmap(Bitmap(BITMAP_TRASH_ID));
        break;
    case 13:
        selectedIcon.setBitmap(Bitmap(BITMAP_USER_ID));
        break;
    }
    selectedIcon.invalidate();
}

// The callback updates the selectedVal on the itemSelected parameter
void Screen1View::scrollWheelAnimateToHandler(int16_t itemSelected)
{
    selectedVal.invalidate();
    Unicode::snprintf(selectedValBuffer, SELECTEDVAL_SIZE, "%d", itemSelected);
}

void Screen1View::scrollListSelected()
{
    selectText.setTypedText(TypedText(T_HEADLINE_SCROLLLIST));

    scrollList.setVisible(true);
    scrollWheel.setVisible(false);
    selectedIcon.setVisible(true);
    selectedVal.setVisible(false);
    scrollWheelFrame.setVisible(false);

    selectText.invalidate();
    scrollList.invalidate();
    scrollWheel.invalidate();
    selectedIcon.invalidate();
    selectedVal.invalidate();
    scrollWheelFrame.invalidate();
}

void Screen1View::scrollWheelSelected()
{
    selectText.setTypedText(TypedText(T_HEADLINE_SCROLLWHEEL));

    scrollList.setVisible(false);
    scrollWheel.setVisible(true);
    selectedIcon.setVisible(false);
    selectedVal.setVisible(true);
    scrollWheelFrame.setVisible(true);

    selectText.invalidate();
    scrollList.invalidate();
    scrollWheel.invalidate();
    selectedIcon.invalidate();
    selectedVal.invalidate();
    scrollWheelFrame.invalidate();
}
