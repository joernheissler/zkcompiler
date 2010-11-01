/** \file hom.hpp
 ** \brief Contains the definition for the Hom class and related data types
 **/
#ifndef ZK_HOM_HPP
#define ZK_HOM_HPP

namespace ZKCompiler {
    class Hom;
}

#include "element/element.hpp"

using namespace ZKCompiler;

namespace ZKCompiler {
    namespace hom {
        /** \brief type of a varref **/
        enum Varref_type { Varref_src, Varref_dst, Varref_var };

        /** \brief variable reference, used by expressions in homomorphisms **/
        struct Varref {
            /** \brief type of reference **/
            Varref_type type;

            /** \brief used for Varref_var; the reference refers to this Element. **/
            Element *e;
            
            /** \brief number of subscripts, used by Varref_src, Varref_dst. **/
            unsigned nsub;
            /** \brief array of subscripts, used by Varref_src, Varref_dst. **/
            unsigned *sub;
        };

        /** \brief type of an expression **/
        enum Expr_type { Expr_id, Expr_min, Expr_max, Expr_inv, Expr_op, Expr_iop, Expr_pow, Expr_ipow, Expr_rnd, Expr_set, Expr_cast };
        /** \brief expression as part of a homomorphism **/
        struct Expr {
            /** \brief type of expression **/
            Expr_type type;

            /** \brief destination variable **/
            Varref *dst;

            /** \brief first operand **/
            Varref *a;

            /** \brief second operand **/
            Varref *b;
        };
    }

    /** \brief Represents a group homomorphism **/
    class Hom {
        public:
            /** \brief constructor for Hom
             ** \param dstElement destination group of homomorphism
             ** \param srcElement source group of homomorphism
             ** \param nexpr number of expressions in \a expr
             ** \param expr pointer into array of \a nexpr expressions
             **
             ** Creates a new Homomorphism; it's supposed to be used by the Parser class, not manually by programmers.
             **/
            Hom(Element *dstElement, Element *srcElement, unsigned nexpr, hom::Expr *expr);

            /** \brief destructor for Hom **/
            ~Hom();

            /** \brief maps the src element from the src group to the dst group and saves into dst element
             ** \param dst destination of the mapping
             ** \param src source of the mapping
             ** \returns nothing
             **
             ** calculates dst = phi(src)
             **/
            void map(Element *dst, Element *src);

            /** \brief get destination group element
             ** \return pointer to destination group element
             **/
            Element *getDstElement();

            /** \brief get source group element
             ** \return pointer to source group element
             **/
            Element *getSrcElement();

        private:
            /** \brief pointer to element of destination group **/
            Element *dstElement;

            /** \brief pointer to element of source group **/
            Element *srcElement;

            /** \brief size of \a expr **/
            unsigned nexpr;

            /** \brief array of expressions **/
            hom::Expr *expr;
    };
}

#endif
