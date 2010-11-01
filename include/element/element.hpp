/** \file element.hpp
 ** \brief Contains the definition of the Element class and Relation enum
 **/
#ifndef ZK_ELEMENT_HPP
#define ZK_ELEMENT_HPP

#include "CodeManagement/ccw/impl/CopyableVariable.hpp"
#include "CodeManagement/core/impl/CodeManager.hpp"

namespace ZKCompiler {
    class Element;

    /** \brief Relation between two \a Elements
     **
     ** There are two kinds of atomic groups:
     ** - ordered groups: two elements are either equal (R_EQ), or one is smaller (R_LT) or greater (R_GT) than the other.
     ** - unordered groups: two elements are either identical (R_ID) or unequal (R_UN).
     **
     ** When comparing tuples, the components are compared pairwise and the results logically ORed together. If the result is 14 (R_LT | R_GT), it's changed to 15.
     **
     ** The enumeration values are bitsets, the meaning of the bits are:
     **
     ** bits:
     ** 1: (at least) one ordered Element is Equal
     ** 2: (at least) one ordered or unordered Element differs
     ** 4: (at least) one ordered Element is Less
     ** 8: (at least) one ordered Element is Greater
     **/

    enum Relation {
        R_ID =                0,   /* only unordered elements;      all are identical */
        R_EQ =             1   ,   /* at least one ordered element; all elements are identical */
        R_UN =         2       ,   /* only unordered elements;      at least one element differs */
        R_NE =         2 + 1   ,   /* at least one ordered element; all ordered elements identical, at least one unordered element differs */
        R_LT =     4 + 2       ,   /* all ordered elements LT */
        R_LE =     4 + 2 + 1   ,   /* at least one ordered element LT and another ordered equal */
        R_GT = 8     + 2       ,   /* all ordered elements GT */
        R_GE = 8     + 2 + 1   ,   /* at least one ordered element GT and another ordered equal */
        R_LG = 8 + 4 + 2 + 1       /* at least one ordered element LT and another ordered GT */
    };

    /** \brief type of an Element. Used to get the real type of an Element **/
    enum Element_Type {
        Element_Atomic,
        Element_Tuple
    };
}

CMD_CODE_DEFINITIONS_BLOCK_EX(ZKCompiler)
{
    CMD_COPYABLE_TYPE(Relation)
}

#include "group/group.hpp"
#include "util/convert.hpp"
#include "hom/hom.hpp"

using namespace ZKCompiler;

namespace ZKCompiler {
    /** \brief Represents an Element of a Group.
     ** This is an abstract class implemented by \a Atomic and \a Tuple **/
    class Element {
        public:
            /** \brief constructor for Element **/
            Element();

            /** \brief destructor for Element **/
            virtual ~Element() = 0;

            /** \brief Apply the homomorphism \a h to \a src
             ** \param h Homomorphism
             ** \param src Parameter to Homomorphism
             **/
            void map(Hom *h, Element *src);

            /** \brief get type of Element
             ** \return Element_Atomic or Element_Tuple
             **/
            virtual Element_Type getType() = 0;

            /** \brief get number of integers in Element
             ** \return number of integers in Element
             **/
            virtual unsigned getSize() = 0;

            /** \brief get sub element, if applicable, or throw an Exception
             ** \param k index of sub element
             ** \return sub Element
             **/
            virtual Element *getSub(unsigned k) = 0;

            /** \brief print the value of an Element
             ** Method used for debugging; Prints the value of an Element to stdout
             **/
            virtual void print() = 0;

            /** \brief construct another element of the same type
             ** \return pointer to Element of same type
             ** Note: The new element is not initialized.
             **/
            virtual Element *element() = 0;

            /** \brief set \a this to the group's identity **/
            virtual void identity() = 0;

            /** \brief set \a this to the group's minimum **/
            virtual void min() = 0;

            /** \brief set \a this to the group's maximum **/
            virtual void max() = 0;

            /** \brief set \a this to the inverse of \a src
             ** \param src operand to inverse
             **/
            virtual void inverse(Element *src) = 0;

            /** \brief apply the group operation to \a src0 and \a src1 and store result in \a this
             ** \param src0 first operand
             ** \param src1 second operand
             **/
            virtual void op(Element *src0, Element *src1) = 0;

            /** \brief apply the group operation to \a src0 and the inverse of \a src1 and store result in \a this
             ** \param src0 first operand
             ** \param src1 second operand
             **/
            virtual void iop(Element *src0, Element *src1) = 0;

            /** \brief raise \a src0 to the power of \a src1 and store the result in \a this
             ** \param src0 base
             ** \param src1 exponent
             **/
            virtual void pow(Element *src0, const CMV::bnz_t& src1) = 0;

            /** \brief raise \a src0 to the power of \a src1 and store the result in \a this
             ** \param src0 base
             ** \param src1 exponent. Must be an Atomic Element.
             **/
            virtual void pow(Element *src0, Element *src1) = 0;

            /** \brief raise \a src0 to the power of \a src1 and store the result in \a this
             ** \param src0 base
             ** \param src1 exponent
             **/
            virtual void pow(Element *src0, CMV::zk_long_t src1) = 0;

            /** \brief raise \a src0 to the power of -\a src1 and store the result in \a this
             ** \param src0 base
             ** \param src1 exponent
             **/
            virtual void ipow(Element *src0, const CMV::bnz_t& src1) = 0;

            /** \brief raise \a src0 to the power of -\a src1 and store the result in \a this
             ** \param src0 base
             ** \param src1 exponent. Must be an Atomic Element.
             **/
            virtual void ipow(Element *src0, Element *src1) = 0;

            /** \brief set \a this to a random element **/
            virtual void random() = 0;

            /** \brief set \a this to a random element, the range is multiplied by \a tightness
             ** \param tightness factor to multiple the range with
             **/
            virtual void random(const CMV::bnz_t& tightness) = 0;

            /** \brief copy \a src to \a this. The groups need not match exactly.
             ** \param src operand
             ** Both groups need to have as components the same total count of Atomic Elements.
             ** Each pair of Atomic Elements must consist of the same number of integers and the values must make sense.
             **/
            virtual void cast(Element *src) = 0;

            /** \brief copy \a src to \a this
             ** \param src operand
             **/
            virtual void set(Element *src) = 0;

            /** \brief copy \a str to \a this
             ** \param str operand. Must be decimal, octal or hexadecimal encoded.
             **/
            virtual void set(CMV::zk_pcchar_t str) = 0;

            /** \brief copy \a src to \a this
             ** \param src operand
             ** The Element must consist of a single integer.
             **/
            virtual void set(const CMV::bnz_t& src) = 0;

            /** \brief copy \a str to \a this
             ** \param str operands. Must be decimal, octal or hexadecimal encoded.
             ** \param n number of operands. Must match size of Element.
             **/
            virtual void set(CMV::zk_pcchar_t const * str, unsigned n) = 0;

            /** \brief copy \a str to \a this
             ** \param src operands.
             ** \param n number of operands. Must match size of Element.
             **/
            virtual void set(const CMV::bnz_t *src, unsigned n) = 0;

            /** \brief copy numbers from an array of pointers
             ** \param vpSrc pointers of sources
             ** \param n number of sources. Must match size of Element.
             **/
            virtual void set(const CMV::bnz_t* vpSrc[], unsigned n) = 0;

            /** \brief copy \a msg to \a this
             ** \param msg message to get values from
             **/
            virtual void set(Message msg) = 0;

            /** \brief copy \a this to \a dst
             ** \param dst destination
             ** The Element must consist of a single integer.
             **/
            virtual void get(CMV::bnz_t& dst) = 0;

            /** \brief copy \a this to \a dst
             ** \param dst destinations.
             ** \param n number of destinations. Must match size of Element.
             **/
            virtual void get(CMV::bnz_t *dst, unsigned n) = 0;

            /** \brief copy const pointers of numbers to \a vpDst
             ** \param vpDst array of pointer destinations.
             ** \param n number of pointer destinations. Must match size of Element.
             **/
            virtual void getPtrs(const CMV::bnz_t* vpDst[], unsigned n) const = 0;

            /** \brief get a Message representing \a this
             ** \return Message containing the values
             ** When assigning the resulting message to another Element of the same type, it will have the same value as \a this.
             **/
            virtual Message get() = 0;

            /** \brief compare two Elements
             ** \param other the Element to compare \a this to. Must be of the same type.
             ** \return Relation describing how both elements relate to each other
             **/
            virtual CMV::Relation cmp(Element *other) = 0;

            /** \brief determine if this Element has been set. FIXME this functionality should be moved into the abstraction of integers.
             ** \return true == is set, false == is not set
             **/
            virtual bool isSet() = 0;

            /** \brief mark this element as set. FIXME remove this API asap **/
            virtual void set() = 0;

            /** \brief mark this element as unset. FIXME remove this API asap **/
            virtual void unset() = 0;
    };
}

#endif
