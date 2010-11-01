/** \file parser.hpp
 ** \brief Contains the definition of the Parser class
 **/
#ifndef ZK_PARSER_HPP
#define ZK_PARSER_HPP

namespace ZKCompiler {
    class Parser;
}

#include "group/group.hpp"
#include "element/element.hpp"
#include "hom/hom.hpp"
#include "sigma/sigma.hpp"

extern "C" {
    /* don't pull in the zkparser interface, just declare that there is a struct by this name */
    struct statementlist;
    struct parserLookup;
}

using namespace ZKCompiler;

namespace ZKCompiler {
    struct ProxyLookup {
        Parser *p;
        const char **groups;
        const char **vars;
        const char **homs;
        const char **sigmas;
    };

    /** \brief c++ interface for the Parser **/
    class Parser {
        public:
            /** \brief constructor for Parser - file version
             ** \param file filename of the input file
             **/
            static Parser *fromFile(const char *file);
            static Parser *fromFile(const char *file, struct ProxyLookup *proxy);

            /** \brief constructor for Parser - string version
             ** \param str contents of the input file (null terminated string)
             **
             ** instead of a file, the input is read from memory
             **/
            static Parser *fromString(const char *str);
            static Parser *fromString(const char *str, struct ProxyLookup *proxy);

            /** \brief destructor for Parser **/
            ~Parser();

            /** \brief get group element by name
             ** \param name group name
             ** \return pointer to Element of group \a name
             **
             ** returns a pointer to a new object every time
             **/
            Element *getElement(const char *name);

            /** \brief get variable by name
             ** \param name variable name
             ** \return pointer to Variable \a name
             **
             ** returns a pointer to the same object every time
             **/
            Element *getVar(const char *name);

            /** \brief get homomorphism by name
             ** \param name homomorphism name
             ** \return pointer to Homomorphism \a name
             **
             ** returns a pointer to the same object every time
             **/
            Hom *getHom(const char *name);

            /** \brief get new Sigma object by name
             ** \param name name of sigma protocol
             ** \return pointer to newly created Sigma object of type \a name
             **
             ** creates a new Sigma object
             **/
            Sigma *getSigma(const char *name);

            /** \brief compute dst = hom(src)
             ** \param dst destination variable
             ** \param hom homomorphism
             ** \param src source variable
             **
             ** Usage:   parser->map(dst, hom, src);
             ** Same as: parser->getVar(dst)->map(parser->getHom(hom), parser->getVar(src));
             **/
            void map(const char *dst, const char *hom, const char *src);

        private:
            static Parser *createGeneric(int(*getchr)(void *), void *arg, struct ProxyLookup *proxy);

            /** \brief private constructor
             **
             ** This constructor is called by fromFile / fromString and converts from zkparser data structures to the c++ interface
             **
             ** \param sl statementlist as returned by zkparser module
             ** \param lu optional lookup parameters
             **/
            Parser(struct statementlist *sl, struct parserLookup *lu);

            /** \brief statementlist as returned by the zkparser module **/
            struct statementlist *sl;

            /** \brief array of groups **/
            Group **groups;

            /** \brief array of variables **/
            Element **vars;

            /** \brief array of homomorphisms **/
            Hom **homs;

            /** \brief arrays of parser elements for proxy lookups **/
            struct parserLookup *lu;
    };
}

#endif
