#ifndef ZK_ELEMENT_TUPLE_HPP
#define ZK_ELEMENT_TUPLE_HPP

#include "element/element.hpp"

namespace ZKCompiler {
    namespace element {
        /** \brief Represents a Tuple Element. **/
        class Tuple : public Element {
            public:
                /** \brief constructor for Tuple
                 ** \param n Size of Tuple / Number of sub Elements
                 ** \param sub array of sub elements (is consumed by Tuple. Do not free/modify later!)
                 **/
                Tuple(unsigned n, Element **sub);
                
                /** \brief destructor for Tuple
                 **/
                ~Tuple();

                /** \brief get type of Element
                 ** \return Element_Tuple
                 **/
                Element_Type getType();

                /** \brief get number of integers in Element
                 ** \return number of integers in Element
                 **/
                unsigned getSize();

                /** \brief get sub element
                 ** \param k index of sub element
                 ** \return sub Element
                 ** throws an exception if \a k is out of range
                 **/
                Element *getSub(unsigned k);

                /** \brief print the value of an Element
                 ** Method used for debugging; Prints the value of an Element to stdout
                 **/
                void print();

                /** \brief construct another element of the same type
                 ** \return pointer to Element of same type
                 ** Note: The new element is not initialized.
                 **/
                Element *element();

                /** \brief set \a this to the group's identity **/
                void identity();

                /** \brief set \a this to the group's minimum **/
                void min();

                /** \brief set \a this to the group's maximum **/
                void max();

                /** \brief set \a this to the inverse of \a src
                 ** \param src operand to inverse
                 **/
                void inverse(Element *src);

                /** \brief apply the group operation to \a src0 and \a src1 and store result in \a this
                 ** \param src0 first operand
                 ** \param src1 second operand
                 **/
                void op(Element *src0, Element *src1);

                /** \brief apply the group operation to \a src0 and the inverse of \a src1 and store result in \a this
                 ** \param src0 first operand
                 ** \param src1 second operand
                 **/
                void iop(Element *src0, Element *src1);

                /** \brief raise \a src0 to the power of \a src1 and store the result in \a this
                 ** \param src0 base
                 ** \param src1 exponent
                 **/
                void pow(Element *src0, const CMV::bnz_t& src1);

                /** \brief raise \a src0 to the power of \a src1 and store the result in \a this
                 ** \param src0 base
                 ** \param src1 exponent. Must be an Atomic Element.
                 **/
                void pow(Element *src0, Element *src1);

                /** \brief raise \a src0 to the power of \a src1 and store the result in \a this
                 ** \param src0 base
                 ** \param src1 exponent
                 **/
                void pow(Element *src0, CMV::zk_long_t src1);

                /** \brief raise \a src0 to the power of -\a src1 and store the result in \a this
                 ** \param src0 base
                 ** \param src1 exponent
                 **/
                void ipow(Element *src0, const CMV::bnz_t& src1);

                /** \brief raise \a src0 to the power of -\a src1 and store the result in \a this
                 ** \param src0 base
                 ** \param src1 exponent. Must be an Atomic Element.
                 **/
                void ipow(Element *src0, Element *src1);

                /** \brief set \a this to a random element **/
                void random();

                /** \brief set \a this to a random element, the range is multiplied by \a tightness
                 ** \param tightness factor to multiple the range with
                 **/
                void random(const CMV::bnz_t& tightness);

                /** \brief copy \a src to \a this. The groups need not match exactly.
                 ** \param src operand
                 ** Both groups need to have as components the same total count of Atomic Elements.
                 ** Each pair of Atomic Elements must consist of the same number of integers and the values must make sense.
                 **/
                void cast(Element *src);

                /** \brief copy \a src to \a this
                 ** \param src operand
                 **/
                void set(Element *src);

                /** \brief copy \a str to \a this
                 ** \param str operand. Must be decimal, octal or hexadecimal encoded.
                 **/
                void set(CMV::zk_pcchar_t str);

                /** \brief copy \a src to \a this
                 ** \param src operand
                 ** The Element must consist of a single integer.
                 **/
                void set(const CMV::bnz_t& src);

                /** \brief copy \a str to \a this
                 ** \param str operands. Must be decimal, octal or hexadecimal encoded.
                 ** \param n number of operands. Must match size of Element.
                 **/
                void set(CMV::zk_pcchar_t const * str, unsigned n);

                /** \brief copy \a src to \a this
                 ** \param src operands.
                 ** \param n number of operands. Must match size of Element.
                 **/
                void set(const CMV::bnz_t *src, unsigned n);

                void set(const CMV::bnz_t* vpSrc[], unsigned n);

                /** \brief copy \a msg to \a this
                 ** \param msg message to get values from
                 **/
                void set(Message msg);

                /** \brief copy \a this to \a dst
                 ** \param dst destination
                 ** The Element must consist of a single integer.
                 **/
                void get(CMV::bnz_t& dst);

                /** \brief copy \a this to \a dst
                 ** \param dst destinations.
                 ** \param n number of destinations. Must match size of Element.
                 **/
                void get(CMV::bnz_t *dst, unsigned n);

                virtual void getPtrs(const CMV::bnz_t* vpDst[], unsigned n) const;

                /** \brief get a Message representing \a this
                 ** \return Message containing the values
                 ** When assigning the resulting message to another Element of the same type, it will have the same value as \a this.
                 **/
                Message get();

                /** \brief compare two Elements
                 ** \param other the Element to compare \a this to. Must be of the same type.
                 ** \return Relation describing how both elements relate to each other
                 **/
                CMV::Relation cmp(Element *other);

                /** \brief determine if this Element has been set. FIXME this functionality should be moved into the abstraction of integers.
                 ** \return true == is set, false == is not set
                 **/
                bool isSet();

                /** \brief mark this element as set. FIXME remove this API asap **/
                void set();

                /** \brief mark this element as unset. FIXME remove this API asap **/
                void unset();
            private:
                /** \brief number of sub elements **/
                unsigned n;

                /** \brief array of sub elements **/
                Element **sub;
                
                /** \brief get linked list of the Atom Elements in a tuple
                 ** \param x tuple Element
                 ** \return linked List
                 **/
                static struct ElementList *getAtomList(Element *x);
        };
    }
}

#endif
