#include "element/element.hpp"

namespace ZKCompiler {
    Element::Element()
    {
        /* nothing to do */
    }
    Element::~Element()
    {
        /* nothing to do */
    }

    void Element::map(Hom *h, Element *src)
    {
        h->map(this, src);
    }
}
