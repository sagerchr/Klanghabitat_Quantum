#include <gui/containers/imageContainer.hpp>
#include <touchgfx\Bitmap.hpp>

imageContainer::imageContainer()
{

}

void imageContainer::updateImage(Bitmap icon)
{
    image.setBitmap(icon);
    image.invalidate();
}
